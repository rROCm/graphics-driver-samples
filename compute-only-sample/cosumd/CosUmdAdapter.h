////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Adapter
//
// Copyright (C) Microsoft Corporation
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "CosAdapter.h"

//==================================================================================================================================
//
// CosUmdAdapter
//
//==================================================================================================================================

class CosUmdAdapter
{
public:

    CosUmdAdapter();
    ~CosUmdAdapter();

    void Open( D3D10DDIARG_OPENADAPTER* pArgs );
    void Close();
    static CosUmdAdapter* CastFrom( D3D10DDI_HADAPTER );
    D3D10DDI_HADAPTER CastTo() const;

public: // DDI entry points for the DDI function table:
    static SIZE_T APIENTRY CalcPrivateDeviceSize( D3D10DDI_HADAPTER, const D3D10DDIARG_CALCPRIVATEDEVICESIZE* );
    static HRESULT APIENTRY CreateDevice( D3D10DDI_HADAPTER, D3D10DDIARG_CREATEDEVICE* );
    static HRESULT APIENTRY CloseAdapter( D3D10DDI_HADAPTER );
    static HRESULT APIENTRY GetSupportedVersions( D3D10DDI_HADAPTER, __inout UINT32* puEntries, __out_ecount_part_opt( *puEntries, *puEntries ) UINT64* pSupportedDDIInterfaceVersions );
    static HRESULT APIENTRY GetCaps( D3D10DDI_HADAPTER, __in const D3D10_2DDIARG_GETCAPS* );

public:
    D3D10DDI_HRTADAPTER m_hRTAdapter;
    UINT m_Interface;
    UINT m_Version;
    const D3DDDI_ADAPTERCALLBACKS* m_pMSCallbacks;

    COSADAPTERINFO  m_cosAdapterInfo;
};

//----------------------------------------------------------------------------------------------------------------------------------
inline CosUmdAdapter* CosUmdAdapter::CastFrom( D3D10DDI_HADAPTER hAdapter )
{
    return static_cast< CosUmdAdapter* >( hAdapter.pDrvPrivate );
}

//----------------------------------------------------------------------------------------------------------------------------------
inline D3D10DDI_HADAPTER CosUmdAdapter::CastTo() const
{
    return MAKE_D3D10DDI_HADAPTER( const_cast< CosUmdAdapter* >( this ) );
}

// Forward declaration
class CosUmdDevice;
