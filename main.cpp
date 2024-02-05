#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <comdef.h>
#include <d3d12.h>
#include "TextureConverter.h"

// コマンドライン引数
enum Argument {
	kApplicationPath, // アプリケーションパス
	kFilePath,		  // 渡されたファイルパス
	NumArgument
};


int main(int argc,char* argv[]) {

	// コマンドライン引数指定なし
	if (argc < NumArgument) {
		// 使い方を表示する
		TextureConverter::OutputUsage();
	}

	//COMライブラリの初期化
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	TextureConverter converter;


	// オプションの数
	int numOptions = argc - NumArgument;
	// オプション配列（ダブルポインタ）
	char** options = argv + NumArgument;

	// テクスチャ変換
	converter.ConvertTextureWICToDDS(argv[kFilePath], numOptions, options);


	//COMライブラリ終了
	CoUninitialize();

	return 0;
}