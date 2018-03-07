#pragma once
#include "stdafx.h"
class FileIO
{
public:
	FileIO();
	~FileIO();

	const std::string DATA_PATH = "userdata.txt";

	void loadHistory();

};

