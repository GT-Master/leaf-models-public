// ManureHousing.cpp : implementation file
//

#include "stdafx.h"
#include "dndc71.h"
#include "dndc_main.h"
#include "ManureHousing.h"
#include "dndc_manure11.h"
#include "SitePara.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern Site_BaseInformation	IData;
/////////////////////////////////////////////////////////////////////////////
// ManureHousing dialog


ManureHousing::ManureHousing(CWnd* pParent /*=NULL*/)
	: CDialog(ManureHousing::IDD, pParent)
{
	//{{AFX_DATA_INIT(ManureHousing)
	m_Stock1 = 0;
	m_AnimalHeads = 0.0f;
	m_FeedRate = 10.0f;
	m_ProteinPercent = 12.0f;
	m_FloorSurfaceType = -1;
	m_FloorArea = 0.0f;
	m_BedType = -1;
	m_BedAmount = 0.0f;
	m_BedCN = 0.0f;
	m_BedFrequency = 0.0f;
	m_Ventilation = -1;
	m_VentRate = 0.0f;
	m_UC = 0.0f;
	m_UD = 0.0f;
	m_UL = 0.0f;
	m_UR = 0.0f;
	m_FC = 0.0f;
	m_FD = 0.0f;
	m_FL = 0.0f;
	m_FR = 0.0f;
	m_RemovalFrequency = 0.0f;
	m_Storage = 0.0f;
	m_TPpercent = 0.4f;
	m_Flash = -1;
	m_unit = 0;
	m_UF = 0.0f;
	m_FF = 0.0f;
	m_FeedLots = 1;
	m_Feedlot = 1;
	m_FeedlotYears = 1;
	m_FeedlotYear = 1;
	//}}AFX_DATA_INIT
}


void ManureHousing::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ManureHousing)
	DDX_Control(pDX, IDC_NutritionModel, m_NutritionModel);
	DDX_Control(pDX, IDC_ExcretionFileList, m_ExcretionFileList);
	DDX_Control(pDX, IDC_IndoorClimateFile, m_IndoorClimateFile);
	DDX_Control(pDX, IDC_AnimalType, m_AnimalType);
	DDX_Control(pDX, IDC_StockFileList, m_StockFileList);
	DDX_Radio(pDX, IDC_Stock2, m_Stock1);
	DDX_Text(pDX, IDC_DairyHeads, m_AnimalHeads);
	DDX_Text(pDX, IDC_DairyFeed, m_FeedRate);
	DDX_Text(pDX, IDC_DairyProtein, m_ProteinPercent);
	DDX_Radio(pDX, IDC_FloorSurface1, m_FloorSurfaceType);
	DDX_Text(pDX, IDC_FloorArea, m_FloorArea);
	DDX_Radio(pDX, IDC_BedType1, m_BedType);
	DDX_Text(pDX, IDC_BedAmount2, m_BedAmount);
	DDX_Text(pDX, IDC_BedCN2, m_BedCN);
	DDX_Text(pDX, IDC_BedNumber2, m_BedFrequency);
	DDX_Radio(pDX, IDC_Ventilation1, m_Ventilation);
	DDX_Text(pDX, IDC_VentRate, m_VentRate);
	DDX_Text(pDX, IDC_UC, m_UC);
	DDX_Text(pDX, IDC_UD, m_UD);
	DDX_Text(pDX, IDC_UL, m_UL);
	DDX_Text(pDX, IDC_UR, m_UR);
	DDX_Text(pDX, IDC_FC, m_FC);
	DDX_Text(pDX, IDC_FD, m_FD);
	DDX_Text(pDX, IDC_FL, m_FL);
	DDX_Text(pDX, IDC_FR, m_FR);
	DDX_Text(pDX, IDC_Frequency, m_RemovalFrequency);
	DDX_Text(pDX, IDC_Storage, m_Storage);
	DDX_Text(pDX, IDC_TP, m_TPpercent);
	DDX_Radio(pDX, IDC_Flash, m_Flash);
	DDX_Radio(pDX, IDC_unit, m_unit);
	DDX_Text(pDX, IDC_UF, m_UF);
	DDX_Text(pDX, IDC_FF, m_FF);
	DDX_Text(pDX, IDC_FEEDLOTS, m_FeedLots);
	DDX_Text(pDX, IDC_FeedLot, m_Feedlot);
	DDX_Text(pDX, IDC_FeedlotYears, m_FeedlotYears);
	DDX_Text(pDX, IDC_FeedLotYear, m_FeedlotYear);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ManureHousing, CDialog)
	//{{AFX_MSG_MAP(ManureHousing)
	ON_BN_CLICKED(IDC_SelStockFile, OnSelStockFile)
	ON_BN_CLICKED(IDC_Stock2, OnStock2)
	ON_BN_CLICKED(IDC_Stock1, OnStock1)
	ON_BN_CLICKED(IDC_Feeds, OnFeeds)
	ON_EN_UPDATE(IDC_TP, OnUpdateTp)
	ON_BN_CLICKED(IDC_unit2, Onunit2)
	ON_BN_CLICKED(IDC_unit, Onunit)
	ON_BN_CLICKED(IDC_Move2, OnMove2)
	ON_BN_CLICKED(IDC_Move1, OnMove1)
	ON_BN_CLICKED(IDC_SelectIndoorClimate, OnSelectIndoorClimate)
	ON_LBN_DBLCLK(IDC_StockFileList, OnDblclkStockFileList)
	ON_LBN_DBLCLK(IDC_IndoorClimateFile, OnDblclkIndoorClimateFile)
	ON_BN_CLICKED(IDC_FeedYr2, OnFeedYr2)
	ON_BN_CLICKED(IDC_FeedYr1, OnFeedYr1)
	ON_BN_CLICKED(IDC_SelectExcretion, OnSelectExcretion)
	ON_BN_CLICKED(IDC_Excretion, OnExcretion)
	ON_LBN_DBLCLK(IDC_ExcretionFileList, OnDblclkExcretionFileList)
	ON_BN_CLICKED(IDC_Ventilation1, OnVentilation1)
	ON_BN_CLICKED(IDC_Stock3, OnStock3)
	ON_EN_KILLFOCUS(IDC_VentRate, OnKillfocusVentRate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

char StockFileName[250], IndoorClimateFile[250], ExcretionFileName[250];
int NutritionModel;
/////////////////////////////////////////////////////////////////////////////
// ManureHousing message handlers


void ManureHousing::OnOK() 
{
	// TODO: Add extra validation here
	SaveFeedlot();

	CString TotalFeedlots;
	FILE *TFL;
	TotalFeedlots.Format("%s\\Result\\inter\\TotalFeedLots_%d", ROOTDIR, m_FeedlotYear);
	TFL=fopen(TotalFeedlots, "w");
	if(TFL==NULL) note(1, TotalFeedlots);
	fprintf(TFL, "%d", m_FeedLots);
	fclose(TFL);

	CDialog::OnOK();
}

BOOL ManureHousing::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_FeedlotYears = IData.years;
	
	if(m_FeedlotYears>0) m_FeedlotYear = 1;

	CString TotalFeedlots;
	FILE *TFL;
	TotalFeedlots.Format("%s\\Result\\inter\\TotalFeedLots_%d", ROOTDIR, m_FeedlotYear);
	TFL=fopen(TotalFeedlots, "r");
	if(TFL==NULL) 
	{
		TFL=fopen(TotalFeedlots, "w");
		fprintf(TFL, "%d", 1);
		fclose(TFL);
		return(0);
		//note(0, TotalFeedlots);
	}

	fscanf(TFL, "%d", &m_FeedLots);
	fclose(TFL);

	UpdateData(FALSE);	

	SetIniPara();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void ManureHousing::SetIniPara()
{
	UpdateData(TRUE);

	char LB[200];
	FILE* ddb;
	sprintf(LB,"%s\\Result\\inter\\UnitSystem", ROOTDIR);
	ddb=fopen(LB, "r");
	if(ddb==NULL) note(0, LB);
	fscanf(ddb, "%d", &m_unit);
	fclose(ddb);

	CString SF;
	FILE* sf;
	SF.Format("%s\\Inter\\ManureHouse_%d_%d.txt", OUTPUT, m_FeedlotYear, m_Feedlot);
	sf=fopen(SF, "r");
	if(sf==NULL)
	{
		CString note;
		note.Format("Cannot create file %s", SF);
		AfxMessageBox(note);
		exit(0);
	}

	fscanf(sf, "%d", &m_Stock1);  
	if(m_Stock1==1)	
	{//use a input file of stock/feed
		fscanf(sf, "%s", StockFileName);
		m_StockFileList.DeleteString(0);
		m_StockFileList.InsertString(0,StockFileName);
	}
	else if(m_Stock1==2)	
	{//use a input file of excretion
		fscanf(sf, "%s", ExcretionFileName);
		m_ExcretionFileList.DeleteString(0);
		m_ExcretionFileList.InsertString(0,ExcretionFileName);
	}
	else if(m_Stock1==3)	
	{//use a nutrition model
		
		fscanf(sf, "%d", &NutritionModel);
		m_NutritionModel.SetCurSel(NutritionModel-1);
		
	}
	else										//use average input data
	{
		int AnimalType, i;
		float AnimalHeads, AnimalFeed, AnimalProtein, AnimalTP;
		//Type: 1 dairy, 2 beef, 3 veal, 4 swine, 5 sheep, 6 goat, 7 horse, 8 layer, 9 brolier, 10 turkey, 11 duck
		
		fscanf(sf, "%d", &i);
		fscanf(sf, "%d", &AnimalType);
		fscanf(sf, "%f %f %f %f", &AnimalHeads, &AnimalFeed, &AnimalProtein, &AnimalTP);
		
		m_AnimalType.SetCurSel(AnimalType-1);
		m_AnimalHeads=AnimalHeads;
		m_FeedRate=AnimalFeed;
		m_ProteinPercent=AnimalProtein;		
		m_TPpercent=AnimalTP;		
	}	
	fscanf(sf, "%f  %d", &m_FloorArea, &m_FloorSurfaceType);//0 slatted floor; 1 conrete floor
	fscanf(sf, "%d  %f  %f  %f", &m_BedType, &m_BedCN, &m_BedFrequency, &m_BedAmount);//0 None, 1 straw, 2 sawdust, 3 dry manure solids, 4 sand
	fscanf(sf, "%d  %f  %s", &m_Ventilation, &m_VentRate, IndoorClimateFile);// 0 natural, 1 fan, -1 indoor climate file	
	fscanf(sf, "%f", &m_RemovalFrequency);
	fscanf(sf, "%f %f %f %f %f", &m_UC, &m_UL, &m_UD, &m_UF, &m_UR);
	fscanf(sf, "%f %f %f %f %f", &m_FC, &m_FL, &m_FD, &m_FF, &m_FR);
	fscanf(sf, "%d", &m_Flash);
	fclose(sf);

	if(m_Ventilation==0) sprintf(IndoorClimateFile, "None");
	m_IndoorClimateFile.DeleteString(0);
	m_IndoorClimateFile.InsertString(0,IndoorClimateFile);

	if(m_unit==1)
	{
		m_FeedRate /= lb_kg;//kg -> lb
		m_FloorArea /= foot2_m2;//m2 -> ft2
		m_BedAmount /= lb_kg;//kg -> lb
		m_VentRate /= foot3_m3;//m3 -> ft3
	}

	CEdit *Edt;
	if(m_Stock1==0)
	{		
		Edt=(CEdit *)GetDlgItem(IDC_SelStockFile);
		Edt->EnableWindow(FALSE);
		//Edt=(CEdit *)GetDlgItem(IDC_Excretion);
		//Edt->EnableWindow(FALSE);
		Edt=(CEdit *)GetDlgItem(IDC_AnimalType);
		Edt->EnableWindow(TRUE);
		Edt=(CEdit *)GetDlgItem(IDC_DairyHeads);
		Edt->EnableWindow(TRUE);
		Edt=(CEdit *)GetDlgItem(IDC_DairyFeed);
		Edt->EnableWindow(TRUE);
		Edt=(CEdit *)GetDlgItem(IDC_DairyProtein);
		Edt->EnableWindow(TRUE);
		Edt=(CEdit *)GetDlgItem(IDC_TP);
		Edt->EnableWindow(TRUE);
	}
	else if(m_Stock1==1)
	{
		Edt=(CEdit *)GetDlgItem(IDC_SelStockFile);
		Edt->EnableWindow(TRUE);
		//Edt=(CEdit *)GetDlgItem(IDC_Excretion);
		//Edt->EnableWindow(TRUE);
		Edt=(CEdit *)GetDlgItem(IDC_AnimalType);
		Edt->EnableWindow(FALSE);
		Edt=(CEdit *)GetDlgItem(IDC_DairyHeads);
		Edt->EnableWindow(FALSE);
		Edt=(CEdit *)GetDlgItem(IDC_DairyFeed);
		Edt->EnableWindow(FALSE);
		Edt=(CEdit *)GetDlgItem(IDC_DairyProtein);
		Edt->EnableWindow(FALSE);
		Edt=(CEdit *)GetDlgItem(IDC_TP);
		Edt->EnableWindow(FALSE);
	}
	else
		{
		Edt=(CEdit *)GetDlgItem(IDC_SelStockFile);
		Edt->EnableWindow(TRUE);
		//Edt=(CEdit *)GetDlgItem(IDC_Excretion);
		//Edt->EnableWindow(TRUE);
		Edt=(CEdit *)GetDlgItem(IDC_AnimalType);
		Edt->EnableWindow(FALSE);
		Edt=(CEdit *)GetDlgItem(IDC_DairyHeads);
		Edt->EnableWindow(FALSE);
		Edt=(CEdit *)GetDlgItem(IDC_DairyFeed);
		Edt->EnableWindow(FALSE);
		Edt=(CEdit *)GetDlgItem(IDC_DairyProtein);
		Edt->EnableWindow(FALSE);
		Edt=(CEdit *)GetDlgItem(IDC_TP);
		Edt->EnableWindow(FALSE);
	}

	
	if(m_unit==1)
	{
		Edt=(CEdit *)GetDlgItem(IDC_kg);
		Edt->EnableWindow(FALSE); 
		Edt=(CEdit *)GetDlgItem(IDC_lb);
		Edt->EnableWindow(TRUE); 
		Edt=(CEdit *)GetDlgItem(IDC_kg2);
		Edt->EnableWindow(FALSE); 
		Edt=(CEdit *)GetDlgItem(IDC_lb2);
		Edt->EnableWindow(TRUE); 
		Edt=(CEdit *)GetDlgItem(IDC_kg3);
		Edt->EnableWindow(FALSE); 
		Edt=(CEdit *)GetDlgItem(IDC_lb3);
		Edt->EnableWindow(TRUE); 
		Edt=(CEdit *)GetDlgItem(IDC_kg4);
		Edt->EnableWindow(FALSE); 
		Edt=(CEdit *)GetDlgItem(IDC_lb4);
		Edt->EnableWindow(TRUE);
	}
	else
	{
		Edt=(CEdit *)GetDlgItem(IDC_kg);
		Edt->EnableWindow(TRUE); 
		Edt=(CEdit *)GetDlgItem(IDC_lb);
		Edt->EnableWindow(FALSE); 
		Edt=(CEdit *)GetDlgItem(IDC_kg2);
		Edt->EnableWindow(TRUE); 
		Edt=(CEdit *)GetDlgItem(IDC_lb2);
		Edt->EnableWindow(FALSE);
		Edt=(CEdit *)GetDlgItem(IDC_kg3);
		Edt->EnableWindow(TRUE); 
		Edt=(CEdit *)GetDlgItem(IDC_lb3);
		Edt->EnableWindow(FALSE);
		Edt=(CEdit *)GetDlgItem(IDC_kg4);
		Edt->EnableWindow(TRUE); 
		Edt=(CEdit *)GetDlgItem(IDC_lb4);
		Edt->EnableWindow(FALSE);
	}		

	UpdateData(FALSE);

	//Onunit2();
}

void ManureHousing::OnStock2() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	if(m_Stock1==0)
	{
		sprintf(StockFileName, "None");
		m_StockFileList.DeleteString(0);
		m_StockFileList.InsertString(0,StockFileName);

		sprintf(ExcretionFileName, "None");
		m_ExcretionFileList.DeleteString(0);
		m_ExcretionFileList.InsertString(0,ExcretionFileName);

		NutritionModel = m_NutritionModel.GetCurSel()+1;
		
	}

	m_Stock1 = 0;

	CEdit *Edt;
	//if(m_Stock1==0)
	{		
		Edt=(CEdit *)GetDlgItem(IDC_SelStockFile);
		Edt->EnableWindow(TRUE);
		//Edt=(CEdit *)GetDlgItem(IDC_Excretion);
		//Edt->EnableWindow(TRUE);
		Edt=(CEdit *)GetDlgItem(IDC_AnimalType);
		Edt->EnableWindow(TRUE);
		Edt=(CEdit *)GetDlgItem(IDC_DairyHeads);
		Edt->EnableWindow(TRUE);
		Edt=(CEdit *)GetDlgItem(IDC_DairyFeed);
		Edt->EnableWindow(TRUE);
		Edt=(CEdit *)GetDlgItem(IDC_DairyProtein);
		Edt->EnableWindow(TRUE);
		Edt=(CEdit *)GetDlgItem(IDC_TP);
		Edt->EnableWindow(TRUE);
		Edt=(CEdit *)GetDlgItem(IDC_NutritionModel);
		Edt->EnableWindow(TRUE);
	}
	/*else
	{
		Edt=(CEdit *)GetDlgItem(IDC_SelStockFile);
		Edt->EnableWindow(TRUE);
		Edt=(CEdit *)GetDlgItem(IDC_AnimalType);
		Edt->EnableWindow(FALSE);
		Edt=(CEdit *)GetDlgItem(IDC_DairyHeads);
		Edt->EnableWindow(FALSE);
		Edt=(CEdit *)GetDlgItem(IDC_DairyFeed);
		Edt->EnableWindow(FALSE);
		Edt=(CEdit *)GetDlgItem(IDC_DairyProtein);
		Edt->EnableWindow(FALSE);
	}*/
}

void ManureHousing::OnStock1() 
{
	// TODO: Add your control notification handler code here
	m_Stock1 = 1;

	CEdit *Edt;
	/*if(m_Stock1==0)
	{		
		Edt=(CEdit *)GetDlgItem(IDC_SelStockFile);
		Edt->EnableWindow(FALSE);
		Edt=(CEdit *)GetDlgItem(IDC_AnimalType);
		Edt->EnableWindow(TRUE);
		Edt=(CEdit *)GetDlgItem(IDC_DairyHeads);
		Edt->EnableWindow(TRUE);
		Edt=(CEdit *)GetDlgItem(IDC_DairyFeed);
		Edt->EnableWindow(TRUE);
		Edt=(CEdit *)GetDlgItem(IDC_DairyProtein);
		Edt->EnableWindow(TRUE);
	}
	else*/
	{
		Edt=(CEdit *)GetDlgItem(IDC_SelStockFile);
		Edt->EnableWindow(TRUE);
		//Edt=(CEdit *)GetDlgItem(IDC_Excretion);
		//Edt->EnableWindow(TRUE);
		Edt=(CEdit *)GetDlgItem(IDC_AnimalType);
		Edt->EnableWindow(FALSE);
		Edt=(CEdit *)GetDlgItem(IDC_DairyHeads);
		Edt->EnableWindow(FALSE);
		Edt=(CEdit *)GetDlgItem(IDC_DairyFeed);
		Edt->EnableWindow(FALSE);
		Edt=(CEdit *)GetDlgItem(IDC_DairyProtein);
		Edt->EnableWindow(FALSE);
		Edt=(CEdit *)GetDlgItem(IDC_TP);
		Edt->EnableWindow(FALSE);
		Edt=(CEdit *)GetDlgItem(IDC_NutritionModel);
		Edt->EnableWindow(FALSE);
	}
}

void ManureHousing::OnFeeds() 
{
	// TODO: Add your control notification handler code here
	Dndc_manure11 ww;
	if(ww.DoModal()==IDOK)
	{
		CString FRC;
		FILE *frc;
		float m_128, m_3, m_127;

		FRC.Format("%s\\FeedComp", INTER);
		frc=fopen(FRC, "r");
		if(frc==NULL) note(0,FRC);
		fscanf(frc, "%f %f %f", &m_128, &m_3, &m_127);
		fclose(frc);
		
		m_FeedRate = m_128;
		m_ProteinPercent = m_3;
		m_TPpercent = m_127;

		UpdateData(FALSE);
	}
}

void ManureHousing::OnUpdateTp() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function to send the EM_SETEVENTMASK message to the control
	// with the ENM_UPDATE flag ORed into the lParam mask.
	
	// TODO: Add your control notification handler code here
	//m_TPpercent = 0.4;
	//UpdateData(FALSE);
	
}

void ManureHousing::Onunit2() 
{
	// TODO: Add your control notification handler code here
	int n_unit = m_unit;

	UpdateData(TRUE);

	if(m_unit==1&&n_unit==0) 
	{
		m_FeedRate /= lb_kg;//kg -> lb
		m_FloorArea /= foot2_m2;//m2 -> feet2
		m_BedAmount /= lb_kg;//kg -> lb
		m_VentRate /= foot3_m3;//m3 -> ft3
	}

	CString DB;
	FILE *db;	
	DB.Format("%s\\Result\\inter\\UnitSystem", ROOTDIR);
	db=fopen(DB, "w");

	CEdit *Edt;
	if(m_unit==1)
	{
		Edt=(CEdit *)GetDlgItem(IDC_kg);
		Edt->EnableWindow(FALSE); 
		Edt=(CEdit *)GetDlgItem(IDC_lb);
		Edt->EnableWindow(TRUE); 
		Edt=(CEdit *)GetDlgItem(IDC_kg2);
		Edt->EnableWindow(FALSE); 
		Edt=(CEdit *)GetDlgItem(IDC_lb2);
		Edt->EnableWindow(TRUE); 
		Edt=(CEdit *)GetDlgItem(IDC_kg3);
		Edt->EnableWindow(FALSE); 
		Edt=(CEdit *)GetDlgItem(IDC_lb3);
		Edt->EnableWindow(TRUE); 
		Edt=(CEdit *)GetDlgItem(IDC_kg4);
		Edt->EnableWindow(FALSE); 
		Edt=(CEdit *)GetDlgItem(IDC_lb4);
		Edt->EnableWindow(TRUE);

		fprintf(db, "%d", 1);
	}
	else
	{
		Edt=(CEdit *)GetDlgItem(IDC_kg);
		Edt->EnableWindow(TRUE); 
		Edt=(CEdit *)GetDlgItem(IDC_lb);
		Edt->EnableWindow(FALSE); 
		Edt=(CEdit *)GetDlgItem(IDC_kg2);
		Edt->EnableWindow(TRUE); 
		Edt=(CEdit *)GetDlgItem(IDC_lb2);
		Edt->EnableWindow(FALSE);
		Edt=(CEdit *)GetDlgItem(IDC_kg3);
		Edt->EnableWindow(TRUE); 
		Edt=(CEdit *)GetDlgItem(IDC_lb3);
		Edt->EnableWindow(FALSE);
		Edt=(CEdit *)GetDlgItem(IDC_kg4);
		Edt->EnableWindow(TRUE); 
		Edt=(CEdit *)GetDlgItem(IDC_lb4);
		Edt->EnableWindow(FALSE);

		fprintf(db, "%d", 0);
	}	
	
	fclose(db);

	UpdateData(FALSE);
}

void ManureHousing::Onunit() 
{
	// TODO: Add your control notification handler code here
	int n_unit = m_unit;

	UpdateData(TRUE);

	if(m_unit==0&&n_unit==1) 
	{
		m_FeedRate *= lb_kg;//lb -> kg
		m_FloorArea *= foot2_m2;//ft2 -> m2 
		m_BedAmount *= lb_kg;//lb -> kg
		m_VentRate *= foot3_m3;//ft3 -> m3
	}

	CString DB;
	FILE *db;	
	DB.Format("%s\\Result\\inter\\UnitSystem", ROOTDIR);
	db=fopen(DB, "w");

	CEdit *Edt;
	if(m_unit==1)
	{
		Edt=(CEdit *)GetDlgItem(IDC_kg);
		Edt->EnableWindow(FALSE); 
		Edt=(CEdit *)GetDlgItem(IDC_lb);
		Edt->EnableWindow(TRUE); 
		Edt=(CEdit *)GetDlgItem(IDC_kg2);
		Edt->EnableWindow(FALSE); 
		Edt=(CEdit *)GetDlgItem(IDC_lb2);
		Edt->EnableWindow(TRUE); 
		Edt=(CEdit *)GetDlgItem(IDC_kg3);
		Edt->EnableWindow(FALSE); 
		Edt=(CEdit *)GetDlgItem(IDC_lb3);
		Edt->EnableWindow(TRUE); 
		Edt=(CEdit *)GetDlgItem(IDC_kg4);
		Edt->EnableWindow(FALSE); 
		Edt=(CEdit *)GetDlgItem(IDC_lb4);
		Edt->EnableWindow(TRUE);

		fprintf(db, "%d", 1);
	}
	else
	{
		Edt=(CEdit *)GetDlgItem(IDC_kg);
		Edt->EnableWindow(TRUE); 
		Edt=(CEdit *)GetDlgItem(IDC_lb);
		Edt->EnableWindow(FALSE); 
		Edt=(CEdit *)GetDlgItem(IDC_kg2);
		Edt->EnableWindow(TRUE); 
		Edt=(CEdit *)GetDlgItem(IDC_lb2);
		Edt->EnableWindow(FALSE);
		Edt=(CEdit *)GetDlgItem(IDC_kg3);
		Edt->EnableWindow(TRUE); 
		Edt=(CEdit *)GetDlgItem(IDC_lb3);
		Edt->EnableWindow(FALSE);
		Edt=(CEdit *)GetDlgItem(IDC_kg4);
		Edt->EnableWindow(TRUE); 
		Edt=(CEdit *)GetDlgItem(IDC_lb4);
		Edt->EnableWindow(FALSE);

		fprintf(db, "%d", 0);
	}	
	
	fclose(db);

	UpdateData(FALSE);
}

void ManureHousing::SaveFeedlot()
{
	UpdateData(TRUE);

	CString snote;

	if(m_UC+m_UL+m_UD+m_UF+m_UR>0.9999&&m_UC+m_UL+m_UD+m_UF+m_UR<0.00001)
	{
		snote.Format("The sum of the fractions must be equal to 1 for liquid waste");
		AfxMessageBox(snote);
		return;
	}

	if(m_FC+m_FL+m_FD+m_FF+m_FR>0.9999&&m_FC+m_FL+m_FD+m_FF+m_FR<0.00001)
	{
		snote.Format("The sum of the fractions must be equal to 1 for solid waster");
		AfxMessageBox(snote);
		return;
	}

	//unit conversion
	float FeedRate, FloorArea, BedAmount, VentRate;
	if(m_unit==0)
	{
		FeedRate = m_FeedRate;
		FloorArea = m_FloorArea;
		BedAmount = m_BedAmount;
		VentRate = m_VentRate;
	}
	else
	{
		FeedRate = m_FeedRate * lb_kg;//lb -> kg
		FloorArea = m_FloorArea * foot2_m2;//feet2 -> m2
		BedAmount = m_BedAmount * lb_kg;//lb -> kg
		VentRate = m_VentRate * foot3_m3;//cubic foot ->cunic m
	}

	CString SF;
	FILE* sf;
	SF.Format("%s\\Result\\Inter\\ManureHouse_%d_%d.txt", ROOTDIR, m_FeedlotYear, m_Feedlot);
	sf=fopen(SF, "w");
	if(sf==NULL) note(1, SF);

	fprintf(sf, "%d\n", m_Stock1);  
	
	if(m_Stock1==1)								//use a input stock/feed file name
		fprintf(sf, "%s\n", StockFileName);
	else if(m_Stock1==2)								//use a input excretion file name
		fprintf(sf, "%s\n", ExcretionFileName);
	else if(m_Stock1==3)
	{						//use a nutrition model
		NutritionModel = m_NutritionModel.GetCurSel()+1;
		fprintf(sf, "%d\n", NutritionModel);
	}
	else	//if(m_Stock1==0)										//use average input data
	{
		int AnimalType = m_AnimalType.GetCurSel()+1;			
		fprintf(sf, "%d\n", 1);
		fprintf(sf, "%d  %f  %f  %f %f\n", AnimalType, m_AnimalHeads, FeedRate, m_ProteinPercent, m_TPpercent);
	}
	
	fprintf(sf, "%f  %d\n", FloorArea, m_FloorSurfaceType);//0 slatted floor; 1 conrete floor
	fprintf(sf, "%d  %f  %f  %f\n", m_BedType, m_BedCN, m_BedFrequency, BedAmount);//0 None, 1 straw, 2 sawdust, 3 dry manure solids, 4 sand
	fprintf(sf, "%d  %f  %s\n", m_Ventilation, VentRate, IndoorClimateFile);// 0 natural, 1 fan
	fprintf(sf, "%f\n", m_RemovalFrequency);
	fprintf(sf, "%f %f %f %f %f\n", m_UC, m_UL, m_UD, m_UF, m_UR);
	fprintf(sf, "%f %f %f %f %f\n", m_FC, m_FL, m_FD, m_FF, m_FR);
	fprintf(sf, "%d\n", m_Flash); 

	fclose(sf);

	/*char LB[200];
	FILE* ddb;
	sprintf(LB,"%s\\Result\\inter\\UnitSystem", ROOTDIR);
	ddb=fopen(LB, "w");
	if(ddb==NULL) note(1, LB);
	fprintf(ddb, "%d", m_unit);
	fclose(ddb);*/

}

void ManureHousing::OnSelectIndoorClimate() 
{
	// TODO: Add your control notification handler code here
	m_IndoorClimateFile.DeleteString(0);

	UpdateData(TRUE);

	m_Ventilation = -1;

	int m_years=1;	
	CString cst;
	CFileDialog  ask( true, NULL, NULL, OFN_HIDEREADONLY | OFN_ALLOWMULTISELECT, 
		"All Files (*.*)|*.*|Data Files (*.dat)|*.dat|Text Files (*.txt)|*.txt||", NULL );
	
	ask.DoModal();
	POSITION pos=ask.GetStartPosition();
	
	int k,num;
	num=m_IndoorClimateFile.GetCount();
	if (num==m_years) return;
	
	k=m_IndoorClimateFile.GetCurSel();
	if (k==-1) k=num;
	else k++;

	//cst=ask.GetFileTitle();
	for (;;)
	{
		cst=ask.GetNextPathName(pos);
		if (cst=="") break;
		strcpy(IndoorClimateFile,cst);
		m_IndoorClimateFile.InsertString(k,IndoorClimateFile);
		if (cst.IsEmpty() || pos==NULL) break;
		if (m_IndoorClimateFile.GetCount()==m_years) break;
		k++;
	}
	m_IndoorClimateFile.SetCurSel(k);

	UpdateData(FALSE);
}

void ManureHousing::OnDblclkStockFileList() 
{
	// TODO: Add your control notification handler code here
	int i,num;
		// delete a selected file from the list
	num=m_StockFileList.GetCount();
	i=m_StockFileList.GetCurSel();
	
	CString fname;
	m_StockFileList.GetText(i,fname);
	m_StockFileList.DeleteString(i);	
	return;
}

void ManureHousing::OnDblclkIndoorClimateFile() 
{
	// TODO: Add your control notification handler code here
	int i,num;
		// delete a selected file from the list
	num=m_IndoorClimateFile.GetCount();
	i=m_IndoorClimateFile.GetCurSel();
	
	CString fname;
	m_IndoorClimateFile.GetText(i,fname);
	m_IndoorClimateFile.DeleteString(i);	
	return;
}

void ManureHousing::OnMove2() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_Feedlot>0)
		SaveFeedlot();

	m_Feedlot++;
	if(m_Feedlot>m_FeedLots) m_Feedlot = m_FeedLots;
	UpdateData(FALSE);
	SetIniPara();
}

void ManureHousing::OnMove1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_Feedlot>0)
		SaveFeedlot();

	m_Feedlot--;
	if(m_Feedlot<0) m_Feedlot = 0;
	UpdateData(FALSE);
	SetIniPara();
}

void ManureHousing::OnFeedYr2() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
		
	if(m_Feedlot>0) SaveFeedlot();

	m_FeedlotYear++;
	if(m_FeedlotYear>m_FeedlotYears) m_FeedlotYear = m_FeedlotYears;
	UpdateData(FALSE);
	
	SetIniPara();
}

void ManureHousing::OnFeedYr1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	
	if(m_Feedlot>0) SaveFeedlot();

	m_FeedlotYear--;
	if(m_FeedlotYear<0) m_FeedlotYear = 0;
	UpdateData(FALSE);
	
	SetIniPara();
}

void ManureHousing::OnSelStockFile() 
{
	// TODO: Add your control notification handler code here
	m_StockFileList.DeleteString(0);
	
	UpdateData(TRUE);
	int m_years=1;	
	CString cst;
	CFileDialog  ask( true, NULL, NULL, OFN_HIDEREADONLY | OFN_ALLOWMULTISELECT, 
		"All Files (*.*)|*.*|Data Files (*.dat)|*.dat|Text Files (*.txt)|*.txt||", NULL );
	
	ask.DoModal();
	POSITION pos=ask.GetStartPosition();
	
	int k,num;
	num=m_StockFileList.GetCount();
	if (num==m_years) return;
	
	k=m_StockFileList.GetCurSel();
	if (k==-1) k=num;
	else k++;

	//cst=ask.GetFileTitle();
	for (;;)
	{
		cst=ask.GetNextPathName(pos);
		if (cst=="") break;
		strcpy(StockFileName,cst);
		m_StockFileList.InsertString(k,StockFileName);
		if (cst.IsEmpty() || pos==NULL) break;
		if (m_StockFileList.GetCount()==m_years) break;
		k++;
	}
	m_StockFileList.SetCurSel(k);
}



void ManureHousing::OnSelectExcretion() 
{
	// TODO: Add your control notification handler code here
	m_ExcretionFileList.DeleteString(0);

	UpdateData(TRUE);
	int m_years=1;	
	CString cst;
	CFileDialog  ask( true, NULL, NULL, OFN_HIDEREADONLY | OFN_ALLOWMULTISELECT, 
		"All Files (*.*)|*.*|Data Files (*.dat)|*.dat|Text Files (*.txt)|*.txt||", NULL );
	
	ask.DoModal();
	POSITION pos=ask.GetStartPosition();
	
	int k,num;
	num=m_ExcretionFileList.GetCount();
	if (num==m_years) return;
	
	k=m_ExcretionFileList.GetCurSel();
	if (k==-1) k=num;
	else k++;

	//cst=ask.GetFileTitle();
	for (;;)
	{
		cst=ask.GetNextPathName(pos);
		if (cst=="") break;
		strcpy(ExcretionFileName,cst);
		m_ExcretionFileList.InsertString(k,ExcretionFileName);
		if (cst.IsEmpty() || pos==NULL) break;
		if (m_ExcretionFileList.GetCount()==m_years) break;
		k++;
	}
	m_ExcretionFileList.SetCurSel(k);
}

void ManureHousing::OnExcretion() 
{
	// TODO: Add your control notification handler code here
	m_Stock1 = 2;

	CEdit *Edt;
	/*if(m_Stock1==0)
	{		
		Edt=(CEdit *)GetDlgItem(IDC_SelStockFile);
		Edt->EnableWindow(FALSE);
		Edt=(CEdit *)GetDlgItem(IDC_AnimalType);
		Edt->EnableWindow(TRUE);
		Edt=(CEdit *)GetDlgItem(IDC_DairyHeads);
		Edt->EnableWindow(TRUE);
		Edt=(CEdit *)GetDlgItem(IDC_DairyFeed);
		Edt->EnableWindow(TRUE);
		Edt=(CEdit *)GetDlgItem(IDC_DairyProtein);
		Edt->EnableWindow(TRUE);
	}
	else*/
	{
		Edt=(CEdit *)GetDlgItem(IDC_SelStockFile);
		Edt->EnableWindow(TRUE);
		//Edt=(CEdit *)GetDlgItem(IDC_Excretion);
		//Edt->EnableWindow(TRUE);
		Edt=(CEdit *)GetDlgItem(IDC_AnimalType);
		Edt->EnableWindow(FALSE);
		Edt=(CEdit *)GetDlgItem(IDC_DairyHeads);
		Edt->EnableWindow(FALSE);
		Edt=(CEdit *)GetDlgItem(IDC_DairyFeed);
		Edt->EnableWindow(FALSE);
		Edt=(CEdit *)GetDlgItem(IDC_DairyProtein);
		Edt->EnableWindow(FALSE);
		Edt=(CEdit *)GetDlgItem(IDC_TP);
		Edt->EnableWindow(FALSE);
	}
}

void ManureHousing::OnDblclkExcretionFileList() 
{
	// TODO: Add your control notification handler code here
	int i,num;
		// delete a selected file from the list
	num=m_ExcretionFileList.GetCount();
	i=m_ExcretionFileList.GetCurSel();
	
	CString fname;
	m_ExcretionFileList.GetText(i,fname);
	m_ExcretionFileList.DeleteString(i);	
	return;
}

void ManureHousing::OnVentilation1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_Ventilation==0) 
	{
		sprintf(IndoorClimateFile, "None");
		m_IndoorClimateFile.DeleteString(0);
		m_IndoorClimateFile.InsertString(0,IndoorClimateFile);
	}
}

void ManureHousing::OnStock3() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

/*	if(m_Stock1==0)
	{
		sprintf(StockFileName, "None");
		m_StockFileList.DeleteString(0);
		m_StockFileList.InsertString(0,StockFileName);

		sprintf(ExcretionFileName, "None");
		m_ExcretionFileList.DeleteString(0);
		m_ExcretionFileList.InsertString(0,ExcretionFileName);

		NutritionModel = m_NutritionModel.GetCurSel()+1;
		
	}

	m_Stock1 = 0;*/

	m_Stock1 = 3;

	CEdit *Edt;
	//if(m_Stock1==0)
	{		
		Edt=(CEdit *)GetDlgItem(IDC_SelStockFile);
		Edt->EnableWindow(FALSE);
		//Edt=(CEdit *)GetDlgItem(IDC_Excretion);
		//Edt->EnableWindow(FALSE);
		Edt=(CEdit *)GetDlgItem(IDC_AnimalType);
		Edt->EnableWindow(FALSE);
		Edt=(CEdit *)GetDlgItem(IDC_DairyHeads);
		Edt->EnableWindow(FALSE);
		Edt=(CEdit *)GetDlgItem(IDC_DairyFeed);
		Edt->EnableWindow(FALSE);
		Edt=(CEdit *)GetDlgItem(IDC_DairyProtein);
		Edt->EnableWindow(FALSE);
		Edt=(CEdit *)GetDlgItem(IDC_TP);
		Edt->EnableWindow(FALSE);
		Edt=(CEdit *)GetDlgItem(IDC_NutritionModel);
		Edt->EnableWindow(TRUE);
	}
	
}

void ManureHousing::OnKillfocusVentRate() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	if(m_VentRate>1000.0) m_VentRate = 1000.0;

	UpdateData(FALSE);

/*	However, it is worth noting a few other publications (also attached) that look at barn ventilation rate.
�Samer et al., 2011 free stall: 275 to 1014 m^3 s-1 ventilation rate. �airflow rate per cow 0.83 to 3 m^3 s-1 per cow. 
�airflow per unit area of .08 to 0.31 m^3 s-1 m-2
�building vent rate of 3546 m^3 h-1 LU-1


�Ngawbie et al., 2009 �building vent rate of 250-265 m^3 h-1 LU-1, spring 401. 



�Teye et al., 2007
�equations for calculating vent rate and some tests run at barns.*/


}
