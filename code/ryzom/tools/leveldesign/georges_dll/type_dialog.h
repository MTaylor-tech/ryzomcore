// Ryzom - MMORPG Framework <http://dev.ryzom.com/projects/ryzom/>
// Copyright (C) 2010  Winch Gate Property Limited
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

/* Copyright, 2000 Nevrax Ltd.
 *
 * This file is part of NEVRAX NEL.
 * NEVRAX NEL is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.

 * NEVRAX NEL is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with NEVRAX NEL; see the file COPYING. If not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
 * MA 02111-1307, USA.
 */

#if !defined(AFX_TYPE_DIALOG_H__435B6164_470D_4E08_B45C_BD23965563A9__INCLUDED_)
#define AFX_TYPE_DIALOG_H__435B6164_470D_4E08_B45C_BD23965563A9__INCLUDED_

#include "base_dialog.h"
#include "edit_list_ctrl.h"

#include "georges/type.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// type_dialog.h : header file
//

class CGeorgesEditView;

class CTypeParentEditListCtrl : public CEditListCtrl
{
	CEditListCtrl::TItemEdit	getItemEditMode (uint item, uint subItem);
	void						getMemComboBoxProp (uint item, uint subItem, std::string &regAdr, bool &browse);
public:
	class CTypeDialog			*Dialog;
};

/////////////////////////////////////////////////////////////////////////////
// CTypeDialog dialog

class CTypeDialog : public CBaseDialog
{
// Construction
public:
	CTypeDialog ();   // standard constructor

	enum
	{
		TypeCombo= 100,
	};

	enum
	{
		CbType = 1,
		CbUI,
		EdDefault,
		EdMin,
		EdMax,
		EdIncrement,
		LtPredef
	};

	// The widgets
	CStatic					LabelType;
	CComboBox				ComboType;
	CStatic					LabelUIType;
	CComboBox				ComboUIType;
	CStatic					LabelDefault;
	CMemoryComboBox			Default;
	CStatic					LabelMin;
	CMemoryComboBox			Min;
	CStatic					LabelMax;
	CMemoryComboBox			Max;
	CStatic					LabelIncrement;
	CMemoryComboBox			Increment;
	CStatic					LabelPreDef;
	CTypeParentEditListCtrl	Predef;
	// CListCtrl		Max;

	// From CBaseDialog
	void onFirstFocus ();
	void onLastFocus ();

	// From CDialog
	virtual void OnOK ();
	virtual void OnCancel ();

	// Get from document, update rightview UI
	void getFromDocument (const NLGEORGES::CType &type);

	// Set to document, update document with rightview UI
	void setTypeToDocument ();
	void setUIToDocument ();
	void setDefaultToDocument ();
	void setMinToDocument ();
	void setMaxToDocument ();
	void setIncrementToDocument ();
	void setPredefToDocument ();

	// Resize widget callback
	void resizeWidgets ();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTypeDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTypeDialog)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TYPE_DIALOG_H__435B6164_470D_4E08_B45C_BD23965563A9__INCLUDED_)
