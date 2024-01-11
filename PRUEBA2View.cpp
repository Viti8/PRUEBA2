
// PRUEBA2View.cpp: implementación de la clase CPRUEBA2View
//

#include "pch.h"
#include "framework.h"
// Se pueden definir SHARED_HANDLERS en un proyecto ATL implementando controladores de vista previa, miniatura
// y filtro de búsqueda, y permiten compartir código de documentos con ese proyecto.
#ifndef SHARED_HANDLERS
#include "PRUEBA2.h"
#endif

#include "PRUEBA2Doc.h"
#include "PRUEBA2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPRUEBA2View

IMPLEMENT_DYNCREATE(CPRUEBA2View, CView)

BEGIN_MESSAGE_MAP(CPRUEBA2View, CView)
	// Comandos de impresión estándar
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CPRUEBA2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Construcción o destrucción de CPRUEBA2View

CPRUEBA2View::CPRUEBA2View() noexcept
{
	// TODO: agregar aquí el código de construcción

}

CPRUEBA2View::~CPRUEBA2View()
{
}

BOOL CPRUEBA2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: modificar aquí la clase Window o los estilos cambiando
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Dibujo de CPRUEBA2View

void CPRUEBA2View::OnDraw(CDC* /*pDC*/)
{
	CPRUEBA2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: agregar aquí el código de dibujo para datos nativos
}


// Impresión de CPRUEBA2View


void CPRUEBA2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CPRUEBA2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Preparación predeterminada
	return DoPreparePrinting(pInfo);
}

void CPRUEBA2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: agregar inicialización adicional antes de imprimir
}

void CPRUEBA2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: agregar limpieza después de imprimir
}

void CPRUEBA2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPRUEBA2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Diagnósticos de CPRUEBA2View

#ifdef _DEBUG
void CPRUEBA2View::AssertValid() const
{
	CView::AssertValid();
}

void CPRUEBA2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPRUEBA2Doc* CPRUEBA2View::GetDocument() const // La versión de no depuración está alineada
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPRUEBA2Doc)));
	return (CPRUEBA2Doc*)m_pDocument;
}
#endif //_DEBUG


// Controladores de mensajes de CPRUEBA2View
