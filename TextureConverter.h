#pragma once
#include<string>

class TextureConverter {
public:
/// <summary>
/// �e�N�X�`����WIC����DDS�ɕϊ�����
/// </summary>
/// <param name = "filepath">�t�@�C���p�X</param>
void ConvertTextureWICToDDS(const std::string& filepath);

private:
	void LoadWICTextureFromFile(const std::string& filepath);

	static std::wstring	 ConvertMultiByteStringToWideString(const std::string& mstring);
};