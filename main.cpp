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

	////argcの数だけ繰り返す
	//for (int i = 0; i < argc; i++) {
	//	//argvのi番を表示
	//	printf(argv[i]);
	//	//改行
	//	printf("\n");
	//}

	assert(argc >= NumArgument);

	//COMライブラリの初期化
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	TextureConverter converter;

	converter.ConvertTextureWICToDDS(argv[kFilePath]);

	//COMライブラリ終了
	CoUninitialize();

	system("pause");
	return 0;
}