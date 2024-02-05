#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <comdef.h>
#include <d3d12.h>
#include "TextureConverter.h"

// �R�}���h���C������
enum Argument {
	kApplicationPath, // �A�v���P�[�V�����p�X
	kFilePath,		  // �n���ꂽ�t�@�C���p�X
	NumArgument
};


int main(int argc,char* argv[]) {

	// �R�}���h���C�������w��Ȃ�
	if (argc < NumArgument) {
		// �g������\������
		TextureConverter::OutputUsage();
	}

	//COM���C�u�����̏�����
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	TextureConverter converter;


	// �I�v�V�����̐�
	int numOptions = argc - NumArgument;
	// �I�v�V�����z��i�_�u���|�C���^�j
	char** options = argv + NumArgument;

	// �e�N�X�`���ϊ�
	converter.ConvertTextureWICToDDS(argv[kFilePath], numOptions, options);


	//COM���C�u�����I��
	CoUninitialize();

	return 0;
}