#include "stdafx.h"
#include "Dndcgo.h"
#include "Source_main.h"
#include "Dndc_tool.h"

#ifdef MANURE 
extern class_manure MData;
extern class_model *DNDC;

void class_manure::digester_BGC(int FN, int GN, 
		int q, int jday, float rcnrvl, float rcnrl, float rcnrr, float rcnh, float rcnb, float *urea, float *doc,
		float *rcvl, float *rcl, float *rcr, float *CRB1, float *CRB2, float *dphum, float *temp, float air_temp, 
		float DayPET, float wind_speed, float *day_wfps, float *soc, float *sph, int *flood_flag, int WTL, float day_WT, 
		float *soil_ph, float *nh4, float *ch4_prod, float *ch4_day_oxid, float *plant_day_ch4, float rcnm, float *son, float *SIN, float *no3, float *no2, 
		float *no, float *n2o, float *n2, float *nh3, float *ch4, float TTT, float *newh, float *w_no2, float *w_nh3, 
		float *w_no3, float *w_nh4, float *wurea, float day_clayn, float *wpool_no, 
		float *DayFlux, int tilq, 
		FILE *fCB, FILE *fNB, float *w_n2o, float *w_n2, int *seed, float *day_ch4, float *anvf, float WaterLeakRate,
		float *co2, float *clay, int LandUse, int FloDays, float *crhl, float *crhr, float *mmm, float *ocini,
		float *h, float *day_C_mine, float *day_N_mine, float *day_N_assim, float DClitter,
		float *litco22, float *litco23, int *st, float DChumads, float EFFAC, float DChumus,
		int wetland_flag, float *ice, float *day_soil_nh3, float *lai, float *PlantTakeN, float *maxmn,
		float leaf_water, float cropht, float base_nh3, float *day_N_demand, float *day_nup, float *day_fixN, 
		float *day_DWater,
		float *day_plant_nh3, float *yr_NH3_deposit, float *plantn, float *clay_nh4, float base_clay_N, float max_clay_N,
		float *wrcvl, float *wrcl, float *wrcr, float *wcrb, float *wcrhl, float *wcrhr, float *whumus, float *wtcavai,
		float *day_ice_N, float *day_ice_doc, float *day_ice_n2o, float *day_ice_n2, float *IniSOC, float *IniSON, 
		float *EndSON, 
		float day_runoff, float *day_runoff_N, float *day_clay_N, 
		float *dsno3, float *dsnh4, float *dsnh3, float *day_dsurea, float *ds_doc, int *crop, float *yr_fixn,
		float till_fact, float *sts, float rainfall, float *O2_old, float *O2, float *vvv, float *ave_anvf,
		int year, double water[25][180], float total_ice, float *day_rco2, int flo_num, float *Eh,
		float *doc_w, float *nh4_w, float *no3_w, float *no2_w, float *no_w, float *n2o_w, float *n2_w,
		float *doc_d, float *nh4_d, float *no3_d, float *no2_d, float *no_d, float *n2o_d, float *ttoo, 
		float ManureAddCN, int ManureDays, float MicrobioIndex, float mRBO, float mFD, int WaterControl, 
		float *assim2, float *fldcap, float by_passf, int NIDay1, int NIDay2,
		float *day_soil_nitrify, float *day_nitrify_NO, float *day_nitrify_N2O, float *day_soil_an_no,
		float *day_soil_an_n2o, float *day_soil_n2, float *Root_Wt, float *day_soil_denitrification,
		float *R_Wt, float *vascularity, float *sop)
{
	float VS;//volatile solids

	sph[GN] = 7.3;

	if(MData.m_DigesterTemp==0) temp[GN] = temp[1];
	else if(MData.m_DigesterTemp==1) temp[GN] = 35.0;
	if(MData.m_DigesterTemp==2) temp[GN] = 55.0;

	digester_decomposition(GN, temp, rcvl, rcl, rcr, CRB1, CRB2,
										 crhl, crhr, dphum, rcnrvl, rcnrl, rcnrr,
										 rcnb, rcnh, rcnm, urea, nh3, nh4,
										 no3, no2, no, n2o, n2, doc, sph);

	VS = doc[GN];
	MData.day_digester_CH4 = 2.0 * VS * MData.m_DigesterCH4 / MData.m_ManureRemoveFrequency[FN];//kg CH4-C/day per digester
	float day_digester_CH4_V = MData.day_digester_CH4 / 12.0 * 22.414 / 1000.0;// kg CH4-C/day -> m3 CH4/day per digester

	MData.yr_digester_ch4 += MData.day_digester_CH4;

	MData.day_digester_CO2 = MData.day_digester_CH4 * 0.6;
	MData.yr_digester_co2 += MData.day_digester_CO2;

	doc[GN] -= (MData.day_digester_CH4 + MData.day_digester_CO2);

	day_wfps[GN] = 1.0;
	
}

void class_manure::digester_decomposition(int GN, float *temp, float *rcvl, float *rcl, float *rcr, float *CRB1, float *CRB2,
										 float *crhl, float *crhr, float *dphum, float rcnrvl, float rcnrl, float rcnrr,
										 float rcnb, float rcnh, float rcnm, float *urea, float *nh3, float *nh4,
										 float *no3, float *no2, float *no, float *n2o, float *n2, float *doc, float *sph)
{
	//Hydrolysis 

	float Ftt = 0.5 * temp[GN] / 55.0;

	float d_rcvl = rcvl[GN] * Ftt; 
	float d_rcl = rcl[GN] * 0.1 * Ftt;
	float d_rcr = rcr[GN] * 0.01 * Ftt;
	float d_CRB1 = CRB1[GN] * 0.1 * Ftt;
	float d_CRB2 = CRB2[GN] * 0.1 * Ftt;
	float d_hdc = (crhl[GN]+crhr[GN]) * 0.1 * Ftt;
	float d_dohum = dphum[GN] * 0.001 * Ftt;
	float d_doc = d_rcvl + d_rcl + d_rcr + d_CRB1 + d_CRB2 + d_hdc + d_dohum;

	rcvl[GN] -= d_rcvl;
	rcl[GN] -= d_rcl;
	rcr[GN] -= d_rcr;
	CRB1[GN] -= d_CRB1;
	CRB2[GN] -= d_CRB2;
	crhl[GN] -= 0.5*d_hdc; 
	crhr[GN] -= 0.5*d_hdc;
	dphum[GN] -= d_dohum;
	doc[GN] += d_doc;

	float d_nh4 = d_rcvl/rcnrvl + d_rcl/rcnrl + d_rcr/rcnrr + d_CRB1/rcnb + d_CRB2/rcnb + d_hdc/rcnh + d_dohum/rcnm;

	nh4[GN] += d_nh4 + urea[GN] + nh3[GN];
	urea[GN] = 0.0;
	nh3[GN] = 0.0;

	//Nitrification
	float dNit = nh4[GN] * 0.001;
	no3[GN] += dNit;
	nh4[GN] -= dNit;

	//Denitrification
	MData.day_digester_n2 = no3[GN] + no2[GN] + no[GN] + n2o[GN] + n2[GN];
	MData.yr_digester_n2 += MData.day_digester_n2;

	no3[GN] = 0.0;
	no2[GN] = 0.0;
	no[GN] = 0.0;
	n2o[GN] = 0.0;
	n2[GN] = 0.0;
	
	MData.day_digester_nh3 = nh4[GN] * sph[GN] / 12.0 * 0.001;
	MData.yr_digester_nh3 += MData.day_digester_nh3;
	nh4[GN] -= MData.day_digester_nh3;

	MData.day_digester_n2o = 0.0;
	MData.yr_digester_n2o += MData.day_digester_n2o;

	MData.day_digester_no = 0.0;
	MData.yr_digester_no += MData.day_digester_no;

	//Total_SOCSON(GN);
}


#endif