
// PRUEBA2.h: archivo de encabezado principal para la aplicación PRUEBA2
//
#pragma once

#ifndef __AFXWIN_H__
	#error "incluir 'pch.h' antes de incluir este archivo para PCH"
#endif

#include "resource.h"       // Símbolos principales


// CPRUEBA2App:
// Consulte PRUEBA2.cpp para obtener información sobre la implementación de esta clase
//

class CPRUEBA2App : public CWinAppEx
{
public:
	CPRUEBA2App() noexcept;


// Reemplazos
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementación
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CPRUEBA2App theApp;
