#include<windows.h>
#include<stdio.h>
int main() {
	char buffer[267];
	DWORD size;
	size = sizeof(buffer);
	GetUserName(&buffer, &size);
	printf("Username: ");
	for (int i = 0; i < 267; i++) {
		if (buffer[i] >= 'a' && buffer[i] <= 'z' || buffer[i] >= 'A' && buffer[i] <= 'Z' || buffer[i] >= '0' && buffer[i] <= '9' || buffer[i] == '-') {
			printf("%c", buffer[i]);
		}
	}
	printf("\n");
	char buffer1[267];
	DWORD size1;
	size1 = sizeof(buffer1);
	GetComputerName(&buffer1, &size1);
	printf("Computername: ");
	for (int i = 0; i < 267; i++) {
		if (buffer1[i] >= 'a' && buffer1[i] <= 'z' || buffer1[i] >= 'A' && buffer1[i] <= 'Z' || buffer1[i] >= '0' && buffer1[i] <= '9' || buffer1[i] == '-') {
			printf("%c", buffer1[i]);
		}
	}
	printf("\n");
	
	SYSTEM_INFO siSysInfo; 
	GetSystemInfo(&siSysInfo);
	printf("System information: \n");
	printf("  OEM ID: %u\n", siSysInfo.dwOemId);
	printf("  Number of processors: %u\n",siSysInfo.dwNumberOfProcessors);
	printf("  Processor type: %u\n", siSysInfo.dwProcessorType);
	printf("  Minimum application address: %lx\n",siSysInfo.lpMinimumApplicationAddress);
	printf("  Maximum application address: %lx\n",siSysInfo.lpMaximumApplicationAddress);
	printf("  Active processor mask: %u\n",
		siSysInfo.dwActiveProcessorMask);
	printf("  Processor architecture: %u\n", siSysInfo.wProcessorArchitecture);
	printf("  Processor level: %u\n", siSysInfo.wProcessorLevel);
	printf("  Processor revision: %u\n", siSysInfo.wProcessorRevision);
	printf("  Reserved: %u\n", siSysInfo.wReserved);
	MEMORYSTATUS lpBuffer;
	GlobalMemoryStatus(&lpBuffer);
	printf("Memory information: \n");
	printf("  Memory load: %u percent \n", lpBuffer.dwMemoryLoad);
	printf("  Total phys: %llu\n", lpBuffer.dwTotalPhys);
	printf("  Avail phys: %llu\n", lpBuffer.dwTotalPhys);
	return 0;
}