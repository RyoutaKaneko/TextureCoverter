#pragma once
#include <string>
#include <DirectXTex.h>

//�e�N�X�`���R���o�[�^�[
class TextureConverter
{
public:
	//�e�N�X�`����WIC����DDS�ɕϊ�����
	void ConvertTextureWICToDDS(const std::string& filePath);

private:
	//�e�N�X�`���t�@�C���ǂݍ���
	void LoadWICTectureFromFile(const std::string& filepath);
	//�}���`�o�C�g����������C�h������ɕϊ�
	static std::wstring ConvertMultiByteStringToWideString(const std::string& mstring);
	//�t�H���_�p�X�ƃt�@�C�����𕪗�����
	void SeparatefilePath(const std::wstring& filePath);
	//DDS�e�N�X�`���Ƃ��ăt�@�C�������o��
	void SaveDDSTextureToFIle();
	//�����o�ϐ�
private:
	//�摜�̏��
	DirectX::TexMetadata metadata_;
	//�摜�C���[�W�̃R���e�i
	DirectX::ScratchImage scratchImage_;
	//�@�f�B���N�g���p�X
	std::wstring directoryPath_;
	//�A�t�@�C����
	std::wstring fileName_;
	//�B�t�@�C���g���q
	std::wstring fileExt_;
};

