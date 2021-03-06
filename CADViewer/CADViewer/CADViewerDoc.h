
// CADViewerDoc.h : interface of the CCADViewerDoc class
//


#pragma once


class CCADViewerDoc : public CDocument
{
protected: // create from serialization only
	CCADViewerDoc();
	DECLARE_DYNCREATE(CCADViewerDoc)

// Attributes
public:
	Handle(AIS_InteractiveContext) myAISContext;
	Handle(V3d_Viewer) myViewer;


// Operations
public:
	Handle(V3d_Viewer) GetViewer(){return myViewer;}
	void DrawSphere(double Radius);
// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CCADViewerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
