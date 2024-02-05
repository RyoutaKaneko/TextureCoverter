#include <cstdio>
#include <cstdlib>
#include "DirectXTex.h"
#include "TextureConverter.h"

enum Argument {
	kApplicationPath,
	kFilePath,

	NumArgument
};


int main(int argc,char* argv[]) {

	////argc�̐������J��Ԃ�
	//for (int i = 0; i < argc; i++) {
	//	//argv��i�Ԃ�\��
	//	printf(argv[i]);
	//	//���s
	//	printf("\n");
	//}

	assert(argc >= NumArgument);

	//COM���C�u�����̏�����
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	TextureConverter converter;

	converter.ConvertTextureWICToDDS(argv[kFilePath]);

	//COM���C�u�����I��
	CoUninitialize();

	system("pause");
	return 0;
}