#include "stdafx.h"
#include "TextureClass.h"

TextureClass::TextureClass()
{
}

TextureClass::TextureClass(const TextureClass&)
{
}

TextureClass::~TextureClass()
{
}

bool TextureClass::Initialize(ID3D11Device*, ID3D11DeviceContext*, char*)
{
	return false;
}

void TextureClass::Shutdown()
{
}

ID3D11ShaderResourceView* TextureClass::GetTexture()
{
	return nullptr;
}

bool TextureClass::LoadTarga(char*, int&, int&)
{
	return false;
}
