#include <stdio.h>

int main()
{
    int pageKB, vspaceMB, virtualAddress;
    printf("Enter the page size in KB: ");
    scanf("%d", &pageKB);
    printf("Enter the virtual space in MB: ");
    scanf("%d", &vspaceMB);
    printf("Enter the virtual address: ");
    scanf("%d", &virtualAddress);

    int pageBYTES = pageKB * 1024L;
    int vspaceBYTES = vspaceMB * 1024L * 1024L;

    if (virtualAddress >= vspaceBYTES)
    {
        printf("Invalid Virtual Address\n");
        return 1;
    }

    int num_pages = vspaceBYTES / pageBYTES;
    int pageTable[num_pages];
    for (int i = 0; i < num_pages; i++)
    {
        pageTable[i] = i;
    }
    int page_number = virtualAddress / pageBYTES;
    int offset = virtualAddress % pageBYTES;

    if (page_number >= num_pages)
    {
        printf("Page Table miss\n");
    }
    else
    {
        printf("Physical Address = <%d, %d>\n", pageTable[page_number], offset);
    }
    return 0;
}
