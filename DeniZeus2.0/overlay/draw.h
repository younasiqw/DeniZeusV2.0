#ifndef HDIRECTX_H
#define HDIRECTX_H

#include "main.h"


#include <Windows.h>
#include <iostream>

#include <d3d9.h>
#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

#include <dwmapi.h>
#pragma comment(lib, "dwmapi.lib")

inline IDirect3D9Ex* p_Object = 0;
inline IDirect3DDevice9Ex* p_Device = 0;
inline D3DPRESENT_PARAMETERS p_Params;

inline ID3DXLine* p_Line;
inline ID3DXFont* pFontSmall = 0;

#include "tools.h"

inline int DirectXInit(HWND hWnd)
{
	if (FAILED(Direct3DCreate9Ex(D3D_SDK_VERSION, &p_Object)))
		exit(1);

	ZeroMemory(&p_Params, sizeof(p_Params));
	p_Params.Windowed = TRUE;
	p_Params.SwapEffect = D3DSWAPEFFECT_DISCARD;
	p_Params.hDeviceWindow = hWnd;
	p_Params.MultiSampleQuality = D3DMULTISAMPLE_NONE;
	p_Params.BackBufferFormat = D3DFMT_A8R8G8B8;
	p_Params.BackBufferWidth = Width;
	p_Params.BackBufferHeight = Height;
	p_Params.EnableAutoDepthStencil = TRUE;
	p_Params.AutoDepthStencilFormat = D3DFMT_D16;

	if (FAILED(p_Object->CreateDeviceEx(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &p_Params, 0, &p_Device)))
		exit(1);

	if (!p_Line)
		D3DXCreateLine(p_Device, &p_Line);

	D3DXCreateFontA(p_Device, 18, 0, 0, 0, false, DEFAULT_CHARSET, OUT_CHARACTER_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, "Calibri", &pFontSmall);

	return 0;
}

#include "../helpers/esp_helpers.h"

inline int Render()
{
	p_Device->Clear(0, 0, D3DCLEAR_TARGET, 0, 1.0f, 0);
	p_Device->BeginScene();

	if (tWnd == GetForegroundWindow())
	{	
		DrawShadowString((char*)"DeniZeus v2.0", 20, 20, 255, 255, 255, pFontSmall);


		for (size_t i = 0; i < esp_boxes.size(); i++)
		{
			if (esp_boxes[i].enabled) {
				DrawBoxWithRect(esp_boxes[i].origin, 4.f, 1,1, 1, 255);
				DrawBoxWithRect(esp_boxes[i].origin, 2.f, esp_boxes[i].clr.r , esp_boxes[i].clr.g, esp_boxes[i].clr.b, 255);
				if(esp_names[i].enabled)
				DrawShadowString((char*)esp_names[i].name.c_str(), esp_names[i].coor.x, esp_names[i].coor.y - GetTextHeight((char*)esp_names[i].name.c_str(), pFontSmall), 255, 255, 255, pFontSmall);
			
				if (esp_health[i].enabled) {
					DrawHealthBarBack(esp_health[i].coor.x - 1, esp_health[i].coor.y - 1, esp_health[i].size.x + 2, esp_health[i].size.y + 2);
					DrawHealthBar(esp_health[i].coor.x, esp_health[i].coor.y, esp_health[i].size.x, esp_health[i].size.y*(esp_health[i].health/100.f), esp_health[i].clr.r, esp_health[i].clr.g, esp_health[i].clr.b);
				}

				if (esp_armor[i].enabled) {
					DrawHealthBarBack(esp_armor[i].coor.x - 1, esp_armor[i].coor.y - 1, esp_armor[i].size.x + 2, esp_armor[i].size.y + 2);
					DrawHealthBar(esp_armor[i].coor.x, esp_armor[i].coor.y, esp_armor[i].size.x, esp_armor[i].size.y * (esp_armor[i].health / 100.f), esp_armor[i].clr.r, esp_armor[i].clr.g, esp_armor[i].clr.b);
				}

			}
		}
	}

	p_Device->EndScene();
	p_Device->PresentEx(0, 0, 0, 0, 0);
	return 0;
}

#endif