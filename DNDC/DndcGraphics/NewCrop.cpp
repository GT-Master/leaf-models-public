// NewCrop.cpp : implementation file
//

#include "stdafx.h"
#include "dndc71.h"
#include "dndc_main.h"
#include "NewCrop.h"
#include "SitePara.h"
#include <io.h>
#include "dndc_tool.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

char * EraseSpace(char *str);
int Si=0;
int v_CropID[95], v_Perennial[95];
float v_max_biomass_C[95], v_grain_fraction[95], v_leaf_fraction[95], v_leafstem_fraction[95], v_root_fraction[95];
float v_GrainCN[95], v_LeafCN[95], v_ShootCN[95], v_RootCN[95], v_TreeAge[95];
float v_WaterDemand[95], v_OptimumT[95], v_TDD[95], v_Nfixation[95], v_Vascularity[95];
char v_CropName[95][100]={"NONE","NONE"};

/////////////////////////////////////////////////////////////////////////////
// NewCrop dialog


NewCrop::NewCrop(CWnd* pParent /*=NULL*/)
	: CDialog(NewCrop::IDD, pParent)
{
	//{{AFX_DATA_INIT(NewCrop)
	m_CropID = 0;
	m_CropName = _T("");
	m_GrainCN = 0.0f;
	m_GrainFraction = 0.0f;
	m_GrowthDevelop = 0.0f;
	m_GrowthReprod = 0.0f;
	m_HeightMax = 0.0f;
	m_LAImax = 0.0f;
	m_Nfixation = 0.0f;
	m_PhotoMax = 0.0f;
	//m_PhotoIni = 0.0f;
	m_PlantCN = 0.0f;
	m_RootCN = 0.0f;
	m_RootFraction = 0.0f;
	m_ShootCN = 0.0f;
	m_ShootFraction = 0.0f;
	m_TDD = 0.0f;
	m_TotalBiomassC = 0.0f;
	m_WaterRequire = 0.0f;
	m_OptimumYield = 0.0f;
	m_Nfix = 0.0f;
	m_Nsoil = 0.0f;
	m_Ndemand = 0.0f;
	m_GrainC = 0.0f;
	m_RootC = 0.0f;
	m_ShootC = 0.0f;
	m_Perennial = FALSE;
	m_Vascularity = 0.0f;
	m_LeafFraction = 0.0f;
	m_LeafC = 0.0f;
	m_LeafCN = 0.0f;
	//}}AFX_DATA_INIT
}


void NewCrop::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(NewCrop)
	DDX_Control(pDX, IDC_SelectCrop, m_SelectCrop);
	DDX_Text(pDX, IDC_CropID, m_CropID);
	DDX_Text(pDX, IDC_CropName, m_CropName);
	DDX_Text(pDX, IDC_GrainCN, m_GrainCN);
	DDX_Text(pDX, IDC_GrainFraction, m_GrainFraction);
	DDX_Text(pDX, IDC_GrowthDevelop, m_GrowthDevelop);
	DDX_Text(pDX, IDC_GrowthReprod, m_GrowthReprod);
	DDX_Text(pDX, IDC_HeightMax, m_HeightMax);
	DDX_Text(pDX, IDC_LAImax, m_LAImax);
	DDX_Text(pDX, IDC_Nfixation, m_Nfixation);
	DDX_Text(pDX, IDC_PhotoMax, m_PhotoMax);
	DDX_Text(pDX, IDC_PhtoIni, m_CropLAI);
	DDX_Text(pDX, IDC_PlantCN, m_PlantCN);
	DDX_Text(pDX, IDC_RootCN, m_RootCN);
	DDX_Text(pDX, IDC_RootFraction, m_RootFraction);
	DDX_Text(pDX, IDC_ShootCN, m_ShootCN);
	DDX_Text(pDX, IDC_ShootFRaction, m_ShootFraction);
	DDX_Text(pDX, IDC_TDD, m_TDD);
	DDX_Text(pDX, IDC_TotalBiomassC, m_TotalBiomassC);
	DDX_Text(pDX, IDC_WaterRequire, m_WaterRequire);
	DDX_Text(pDX, IDC_OptimumYield, m_OptimumYield);
	DDX_Text(pDX, IDC_Nfix, m_Nfix);
	DDX_Text(pDX, IDC_Nsoil, m_Nsoil);
	DDX_Text(pDX, IDC_Ndemand, m_Ndemand);
	DDX_Text(pDX, IDC_GrainC, m_GrainC);
	DDX_Text(pDX, IDC_RootC, m_RootC);
	DDX_Text(pDX, IDC_ShootC, m_ShootC);
	DDX_Check(pDX, IDC_Perennial, m_Perennial);
	DDX_Text(pDX, IDC_Vascularity, m_Vascularity);
	DDX_Text(pDX, IDC_LeafFRaction, m_LeafFraction);
	DDX_Text(pDX, IDC_LeafC, m_LeafC);
	DDX_Text(pDX, IDC_LeafCN, m_LeafCN);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(NewCrop, CDialog)
	//{{AFX_MSG_MAP(NewCrop)
	ON_CBN_SELCHANGE(IDC_SelectCrop, OnSelchangeSelectCrop)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_EN_KILLFOCUS(IDC_GrainFraction, OnKillfocusGrainFraction)
	ON_EN_KILLFOCUS(IDC_OptimumYield, OnKillfocusOptimumYield)
	ON_EN_KILLFOCUS(IDC_ShootFRaction, OnKillfocusShootFRaction)
	ON_EN_KILLFOCUS(IDC_ShootCN, OnKillfocusShootCN)
	ON_EN_KILLFOCUS(IDC_Nfixation, OnKillfocusNfixation)
	ON_BN_CLICKED(IDC_Check, OnCheck)
	ON_EN_KILLFOCUS(IDC_GrainCN, OnKillfocusGrainCN)
	ON_EN_KILLFOCUS(IDC_RootCN, OnKillfocusRootCN)
	ON_EN_CHANGE(IDC_CropName, OnChangeCropName)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// NewCrop message handlers

void NewCrop::OnSelchangeSelectCrop() 
{
	// TODO: Add your control notification handler code here
	CString CCrop;
	FILE *fCrop;

	char fff[300];	
	int CropCode, i, Perennial=0;
	//char v_CropName[95][100]={"NONE","NONE"};
	
	UpdateData(TRUE);
	CropType = m_SelectCrop.GetCurSel();

	///////////////////////////////////////////////////////////////////////////////////////////
	
	ReadCropPara1(v_CropID, v_CropName, v_max_biomass_C, v_grain_fraction, v_leaf_fraction,
				  v_leafstem_fraction, v_root_fraction, v_GrainCN, v_LeafCN,
				  v_ShootCN, v_RootCN, v_WaterDemand, v_OptimumT, 
				  v_TDD, v_Nfixation, v_Vascularity, v_Perennial, v_TreeAge);

	///////////////////////////////////////////////////////////////////////////////////////////

	if(v_Perennial[CropType]==1) m_Perennial=TRUE;
	else m_Perennial=FALSE;
	
	m_CropID = v_CropID[CropType];
	m_CropName.Format("%s", v_CropName[CropType]);
	m_TotalBiomassC = v_max_biomass_C[CropType];
	m_GrainFraction = v_grain_fraction[CropType];
	m_LeafFraction = v_leaf_fraction[CropType];
	m_ShootFraction = v_leafstem_fraction[CropType];
	m_RootFraction = v_root_fraction[CropType];	
	m_GrainCN = v_GrainCN[CropType];
	m_RootCN = v_RootCN[CropType];
	m_LeafCN = v_LeafCN[CropType];
	m_ShootCN = v_ShootCN[CropType];
	m_WaterRequire = v_WaterDemand[CropType];
	m_LAImax = v_OptimumT[CropType];	
	m_TDD = v_TDD[CropType];
	m_Nfixation = v_Nfixation[CropType];
	m_Vascularity = v_Vascularity[CropType];
	m_CropLAI = v_TreeAge[CropType];
	//m_PhotoIni = para[17];
	//m_PhotoMax = para[18];
	//m_GrowthDevelop = para[19];
	//m_GrowthReprod = para[20];
	m_HeightMax = 1.0;

	m_OptimumYield = m_TotalBiomassC / 0.4 * m_GrainFraction;
	
	m_Ndemand = m_GrainC / m_GrainCN + m_LeafC / m_LeafCN + m_ShootC / m_ShootCN + m_RootC / m_RootCN;
	m_PlantCN = m_TotalBiomassC / m_Ndemand;

	UpdateData(FALSE);

	OnCheck();
}

void NewCrop::OnRadio1() 
{
	// TODO: Add your control notification handler code here

	int i;
	FILE *fp;
	char fname[256];
	char fff[200];

	sprintf(fname,"%s\\Library\\lib_crop\\crop.lst", ROOTDIR);
	fp=fopen(fname,"r");
	if (fp==NULL) 
	{	
		CString note;
		note.Format("Cannot find file %s", fname);
		AfxMessageBox(note);
		exit(0);
	}

	fscanf(fp,"%d",&CropNum);
	
	for (i=0;i<CropNum;i++)
	{
		fscanf(fp,"%d %s",&cropid[i], fff);
		cropname[i].Format("%s", fff);
	}
	fclose(fp);

	m_CropID = CropNum;

	m_CropName.Format("");
	m_TotalBiomassC = 0.0;
	m_GrainFraction = 0.0;
	m_ShootFraction = 0.0;
	m_RootFraction = 0.0;
	m_PlantCN = 0.0;
	m_GrainCN = 0.0;
	m_RootCN = 0.0;
	m_ShootCN = 0.0;
	m_WaterRequire = 0.0;
	m_LAImax = 0.0;
	m_HeightMax = 0.0;
	m_TDD = 0.0;
	m_Nfixation = 1.0;
	m_Vascularity = 0.0;
	m_Perennial=FALSE;

/*	m_PhotoIni = 0.0;
	m_PhotoMax = 0.0;
	m_GrowthDevelop = 0.0;
	m_GrowthReprod = 0.0;
	m_OptimumYield = 0.0;
	m_Nfix = 0.0;
	m_Nsoil = 0.0;
	m_Ndemand = 0.0;
	m_GrainC = 0.0;
	m_RootC = 0.0;
	m_ShootC = 0.0;*/

	NewCropFlag=1;

	UpdateData(FALSE);
	
}

void NewCrop::OnRadio2() 
{
	// TODO: Add your control notification handler code here
	
	m_CropID = 0;
	m_CropName.Format("");
	m_TotalBiomassC = 0.0;
	m_GrainFraction = 0.0;
	m_ShootFraction = 0.0;
	m_RootFraction = 0.0;
	m_PlantCN = 0.0;
	m_GrainCN = 0.0;
	m_RootCN = 0.0;
	m_ShootCN = 0.0;
	m_WaterRequire = 0.0;
	m_LAImax = 0.0;
	m_HeightMax = 0.0;
	m_TDD = 0.0;
	m_Nfixation = 1.0;
	m_CropLAI = 0.0;
	m_PhotoMax = 0.0;
	m_GrowthDevelop = 0.0;
	m_GrowthReprod = 0.0;

	m_OptimumYield = 0.0;
	m_Nfix = 0.0;
	m_Nsoil = 0.0;
	m_Ndemand = 0.0;
	m_GrainC = 0.0;
	m_RootC = 0.0;
	m_ShootC = 0.0;

	NewCropFlag=0;

	UpdateData(FALSE);
}

BOOL NewCrop::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SetPlantList();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL NewCrop::SetPlantList()
{
	int i,id,CropNum,Si=m_SelectCrop.GetCurSel();
	FILE *fCrop;
	char fname[256];
	//char v_CropName[95][100]={"NONE","NONE"};

	///////////////////////////////////////////////////////////////////////////////////////////
	
	ReadCropPara1(v_CropID, v_CropName, v_max_biomass_C, v_grain_fraction, v_leaf_fraction,
				  v_leafstem_fraction, v_root_fraction, v_GrainCN, v_LeafCN,
				  v_ShootCN, v_RootCN, v_WaterDemand, v_OptimumT, 
				  v_TDD, v_Nfixation, v_Vascularity, v_Perennial, v_TreeAge);

	///////////////////////////////////////////////////////////////////////////////////////////

	m_SelectCrop.ResetContent();
	
	for (i=0;i<=90;i++)
	{
		EraseFBSpace(v_CropName[i]);
		sprintf(fname,"%d %s",i,v_CropName[i]);
		m_SelectCrop.AddString(fname);
	}

	if (Si>=0) m_SelectCrop.SetCurSel(Si);
	return 0;
}

char * EraseSpace(char *str)
{
	while (str[0]==32)
	{
		sprintf(str,"%s",str+1);
	}
	int l=strlen(str);
	if (l>0) 
	{
		while (str[l-1]<=32)
		{
			str[strlen(str)-1]='\0';
			l=strlen(str);
		}
	}
	return str;
}

void NewCrop::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);

	if(m_Nfixation<1.0)
	{
		CString note;
		note.Format("N fixation index must be >= 1");
		AfxMessageBox(note);
		return;
	}

	if(m_LAImax<5.0||m_LAImax>35)
	{
		CString note;
		note.Format("Please check if optimum temperature for crop growth is correct");
		AfxMessageBox(note);
		return;
	}

	float TT = m_GrainFraction+m_LeafFraction+m_ShootFraction+m_RootFraction;
	if(TT>1.000001||TT<0.99999)
	{
		CString note;
		note.Format("Grain fraction + shoot fraction + root fraction = %f. Please re-set the fractions", m_GrainFraction+m_ShootFraction+m_RootFraction);
		AfxMessageBox(note);
		
		UpdateData(FALSE);
		return;
	}
	
	///////////////////////////////////////////////////////////////////////////////////////////
	int CCD = m_CropID;

	if(v_CropID[CCD]!=CCD) 
	{
		CString note;
		note.Format("Error in crop parameter file");
		AfxMessageBox(note);
		return;
	}

	sprintf(v_CropName[CCD], "%s", m_CropName);
	v_Perennial[CCD] = m_Perennial;
	v_max_biomass_C[CCD] = m_TotalBiomassC;
	v_grain_fraction[CCD] = m_GrainFraction;
	v_leaf_fraction[CCD] = m_LeafFraction;
	v_leafstem_fraction[CCD] = m_ShootFraction;
	v_root_fraction[CCD] = m_RootFraction;
	v_GrainCN[CCD] = m_GrainCN;
	v_LeafCN[CCD] = m_LeafCN;
	v_ShootCN[CCD] = m_ShootCN;
	v_RootCN[CCD] = m_RootCN;
	v_WaterDemand[CCD] = m_WaterRequire;
	v_OptimumT[CCD] = m_LAImax;
	v_TDD[CCD] = m_TDD;
	v_Nfixation[CCD] = m_Nfixation;
	v_Vascularity[CCD] = m_Vascularity;
	v_TreeAge[CCD] = m_CropLAI;
		
	///////////////////////////////////////////////////////////////////////////////////////////

	int i;
	CString TTL[16] = {"", "Crop_ID","Crop_name","max_biomass_C","grain_fraction","leaf+stem_fraction","root_fraction","GrainCN","ShootCN","RootCN","WaterDemand","OptimumT","TDD","Nfixation","Vascularity","PerennialCrop"};
	CString UT[16] = {"", "Unit","None","kgC/ha","None","None","None","None","None","None","kg_water/kg_DW","Degree_C","Degree_C","None","None","None"};

	CString CCrop;
	FILE* fCrop;

	CCrop.Format("%sLibrary\\lib_crop\\Crop_parameters.txt", ROOTDIR);
	fCrop = fopen(CCrop, "w");
	if(fCrop==NULL) note(1, CCrop);
	else
	{
		fprintf(fCrop, "%s\n", "Physiology and phenology parameters for plants simulated in DNDC");

		for(i=1; i<=15; i++) fprintf(fCrop, "%15s ", TTL[i]);
		fprintf(fCrop, "\n");

		for(i=0; i<=90; i++)
		{
			fprintf(fCrop, "%15d %15s", v_CropID[i], v_CropName[i]);
			fprintf(fCrop, "%15.2f %15.2f %15.2f %15.2f %15.2f %15.2f %15.2f %15.2f %15.2f %15.2f %15.2f %15.2f %15.2f %15.2f", 
				v_max_biomass_C[i], v_grain_fraction[i], v_leaf_fraction[i], v_leafstem_fraction[i], v_root_fraction[i], 
				v_GrainCN[i], v_LeafCN[i], v_ShootCN[i], v_RootCN[i], v_WaterDemand[i], v_OptimumT[i], v_TDD[i], 
				v_Nfixation[i], v_Vascularity[i]);
			fprintf(fCrop, "%15d", v_Perennial[i]);//, v_TreeAge[i]);
			fprintf(fCrop, "\n");
		}

		for(i=1; i<=15; i++) fprintf(fCrop, "%15s ", UT[i]);
		fprintf(fCrop, "\n");

		fclose(fCrop);
	}

	CDialog::OnOK();
}


void NewCrop::OnKillfocusOptimumYield() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_OptimumYield <= 0.0) m_OptimumYield = 0.01;
	UpdateData(FALSE);
	OnCheck();
}

void NewCrop::OnKillfocusGrainFraction() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_GrainFraction <= 0.0) m_GrainFraction = 0.01;
	m_RootFraction = 1.0 - (m_GrainFraction + m_ShootFraction);
	UpdateData(FALSE);
	OnCheck();
}

void NewCrop::OnKillfocusShootFRaction() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_RootFraction = 1.0 - (m_GrainFraction + m_ShootFraction);
	UpdateData(FALSE);
	OnCheck();
	/*if(m_RootFraction<= 0.0) 
	{
		CString note;
		note.Format("Root fraction = %f. Please re-set grain or shoot fraction", m_RootFraction);
		AfxMessageBox(note);
		m_GrainFraction = 0.0;
		m_ShootFraction = 0.0;
		m_RootFraction = 0.0;
		UpdateData(FALSE);
		return;
	}
	
	m_TotalBiomassC = m_OptimumYield * 0.4 / m_GrainFraction;
	m_GrainC = m_TotalBiomassC * m_GrainFraction;
	m_ShootC = m_TotalBiomassC * m_ShootFraction;
	m_RootC = m_TotalBiomassC * m_RootFraction;

	UpdateData(FALSE);*/
}

void NewCrop::OnKillfocusShootCN() 
{
	// TODO: Add your control notification handler code here
	OnCheck();
/*	UpdateData(TRUE);
	float TC, TN;
	TC = m_TotalBiomassC;
	TN = m_GrainC / m_GrainCN + m_ShootC / m_ShootCN + m_RootC / m_RootCN;
	m_PlantCN = TC / TN;

	m_Ndemand = TN;
	
	UpdateData(FALSE);*/
}

void NewCrop::OnKillfocusNfixation() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	m_Nsoil = m_Ndemand / m_Nfixation;
	m_Nfix = m_Ndemand - m_Nsoil;

	UpdateData(FALSE);
	OnCheck();
}

void NewCrop::OnCheck() 
{
	// TODO: Add your control notification handler code here
	float TC, TN;

	UpdateData(TRUE);

	if(m_Nfixation<1.0)
	{
		CString note;
		note.Format("N fixation index must be higher than 1");
		AfxMessageBox(note);
		return;
	}

	m_RootFraction = 1.0 - (m_GrainFraction + m_LeafFraction + m_ShootFraction);
	UpdateData(FALSE);
	if(m_RootFraction<= 0.0) 
	{
		CString note;
		note.Format("Root fraction = %f. Please re-set grain or shoot fraction", m_RootFraction);
		AfxMessageBox(note);
		m_GrainFraction = 0.0;
		m_LeafFraction = 0.0;
		m_ShootFraction = 0.0;
		m_RootFraction = 0.0;
		UpdateData(FALSE);
		return;
	}
	
	m_TotalBiomassC = m_OptimumYield * 0.4 / m_GrainFraction;
	m_GrainC = m_TotalBiomassC * m_GrainFraction;
	m_LeafC = m_TotalBiomassC * m_LeafFraction;
	m_ShootC = m_TotalBiomassC * m_ShootFraction;
	m_RootC = m_TotalBiomassC * m_RootFraction;

	TC = m_TotalBiomassC;
	TN = m_GrainC / m_GrainCN + m_LeafC / m_LeafCN + m_ShootC / m_ShootCN + m_RootC / m_RootCN;
	m_PlantCN = TC / TN;

	m_Ndemand = TN;
	m_Nsoil = m_Ndemand / m_Nfixation;
	m_Nfix = m_Ndemand - m_Nsoil;

	UpdateData(FALSE);
	
}


void NewCrop::OnKillfocusGrainCN() 
{
	// TODO: Add your control notification handler code here
	OnCheck();
}

void NewCrop::OnKillfocusRootCN() 
{
	// TODO: Add your control notification handler code here
	OnCheck();
}

void NewCrop::OnChangeCropName() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}
