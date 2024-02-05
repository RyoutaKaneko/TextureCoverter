#pragma once
#include<string>

class TextureConverter {
public:
/// <summary>
/// テクスチャをWICからDDSに変換する
/// </summary>
/// <param name = "filepath">ファイルパス</param>
void ConvertTextureWICToDDS(const std::string& filepath);

private:
	void LoadWICTextureFromFile(const std::string& filepath);

	static std::wstring	 ConvertMultiByteStringToWideString(const std::string& mstring);
};