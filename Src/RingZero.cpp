
// Windows Ring 0 Demo by ali90taz

#include <cstdio>
#include <Windows.h>
#include "OlsApi.h"

#define VERSION "1.0.0b"

// Some ANSI stuff

#define NORMAL "\x1B[0m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN "\x1B[36m"
#define WHITE "\x1B[37m"

typedef enum _DLL_STATUS_ID {
	OLS_DLL_NO_ERROR,
	OLS_DLL_UNSUPPORTED_PLATFORM,
	OLS_DLL_DRIVER_NOT_LOADED,
	OLS_DLL_DRIVER_NOT_FOUND,
	OLS_DLL_DRIVER_UNLOADED,
	OLS_DLL_DRIVER_NOT_LOADED_ON_NETWORK,
	OLS_DLL_RESERVED_1,
	OLS_DLL_RESERVED_2,
	OLS_DLL_RESERVED_3,
	OLS_DLL_UNKNOWN_ERROR,
	END
} DLL_STATUS_ID;

const char* DLL_STATUS_MSG[DLL_STATUS_ID::END];

static void assignMessages() {
	DLL_STATUS_MSG[DLL_STATUS_ID::OLS_DLL_NO_ERROR] = "No error";
	DLL_STATUS_MSG[DLL_STATUS_ID::OLS_DLL_UNSUPPORTED_PLATFORM] = "Unsupported Platform";
	DLL_STATUS_MSG[DLL_STATUS_ID::OLS_DLL_DRIVER_NOT_LOADED] = "Driver not loaded";
	DLL_STATUS_MSG[DLL_STATUS_ID::OLS_DLL_DRIVER_NOT_FOUND] = "Driver not found";
	DLL_STATUS_MSG[DLL_STATUS_ID::OLS_DLL_DRIVER_UNLOADED] = "Driver unloaded by other process";
	DLL_STATUS_MSG[DLL_STATUS_ID::OLS_DLL_DRIVER_NOT_LOADED_ON_NETWORK] = "Driver not loaded because of executing on Network Drive";
	DLL_STATUS_MSG[DLL_STATUS_ID::OLS_DLL_RESERVED_1] = "Reserved";
	DLL_STATUS_MSG[DLL_STATUS_ID::OLS_DLL_RESERVED_2] = "Reserved";
	DLL_STATUS_MSG[DLL_STATUS_ID::OLS_DLL_RESERVED_3] = "Reserved";
	DLL_STATUS_MSG[DLL_STATUS_ID::OLS_DLL_NO_ERROR] = "Unknown error";
}

static void showHeader() {
	printf(
		"%sWindows Ring 0 Demo - Version %s - Designed by ali90taz" "\n\n",
		GREEN, VERSION
	);
}

int main(int argc, const char* argv[]) {

	system("cls");
	assignMessages();

	if (InitializeOls()) {
		showHeader();
		printf("%sProcessor Instructions: " "\n\n", YELLOW);
		printf("%sCPUID: %s" "\n", MAGENTA, IsCpuid() ? GREEN "TRUE" : RED "FALSE");
		printf("%sRDMSR: %s" "\n", MAGENTA, IsMsr() ? GREEN "TRUE" : RED "FALSE");
		printf("%sRDTSC: %s" "\n\n", MAGENTA, IsTsc() ? GREEN "TRUE" : RED "FALSE");
	}
	else {
		showHeader();
		printf("%sError: %s.", RED, DLL_STATUS_MSG[GetDllStatus()]);
	}

	printf("%s\n", NORMAL);
	DeinitializeOls();
	return 0;
}