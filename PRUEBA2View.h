
// PRUEBA2View.h: interfaz de la clase CPRUEBA2View
//

#pragma once


class CPRUEBA2View : public CView
{
protected: // Crear sólo a partir de serialización
	CPRUEBA2View() noexcept;
	DECLARE_DYNCREATE(CPRUEBA2View)

// Atributos
public:
	CPRUEBA2Doc* GetDocument() const;

// Operaciones
public:

// Reemplazos
public:
	virtual void OnDraw(CDC* pDC);  // Reemplazado para dibujar esta vista
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementación
public:
	virtual ~CPRUEBA2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Funciones de asignación de mensajes generadas
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Versión de depuración en PRUEBA2View.cpp
inline CPRUEBA2Doc* CPRUEBA2View::GetDocument() const
   { return reinterpret_cast<CPRUEBA2Doc*>(m_pDocument); }
#endif

