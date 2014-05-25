//{{AFX_INCLUDES()
//#include "msflexgrid.h"
//}}AFX_INCLUDES
#if !defined(AFX_SITEPAGE7_H__D840512B_58F2_11D3_A713_005004A6D36F__INCLUDED_)
#define AFX_SITEPAGE7_H__D840512B_58F2_11D3_A713_005004A6D36F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SitePage7.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// SitePage7 dialog

class SitePage7 : public CPropertyPage
{
	DECLARE_DYNCREATE(SitePage7)

// Construction
public:
	SitePage7();
	~SitePage7();
	//BOOL CheckManN();
	//BOOL CheckManID();
	void demo(void);

	int ManuID[300], ManuMonth[300], ManuDay[300], ManuType[300], ManuMethod[300];
	float ManuAmount[300], ManuCN[300], ManuN[300];

// Dialog Data
	//{{AFX_DATA(SitePage7)
	enum { IDD = IDD_PROPPAGE7 };
	CComboBox	m_ManType;
	CListCtrl	m_ManList;
	int		m_ManID;
	int		m_ManMonth;
	int		m_ManN;
	int		m_ManDay;
	float	m_ManAmount;
	float	m_ManC_N;
	float	m_kgN;
	int		m_ManureMethod;
	int		m_unit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(SitePage7)
	public:
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(SitePage7)
	afx_msg void OnManAccept();
	afx_msg void OnFerLast();
	afx_msg void OnFerNext();
	afx_msg void OnKillfocusCombo1();
	afx_msg void OnKillfocusManMonth();
	afx_msg void OnKillfocusManDay();
	afx_msg void OnKillfocusManAmount();
	afx_msg void OnKillfocusManCN();
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeCombo1();
	afx_msg void Onunit();
	afx_msg void Onunit2();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SITEPAGE7_H__D840512B_58F2_11D3_A713_005004A6D36F__INCLUDED_)
