#include <x68k/iocs.h>
#include <stdio.h>

void print_usage(const char *prog_name) {
  printf("Usage: %s <CRTMOD_value>\n", prog_name);
  printf("  <CRTMOD_value>: A number between 0 and 255 (decimal)\n"
         "  -h : Show this help message\n"
         "Example:\n"
         "  %s 0   (Sets CRTMOD to 0, which is 512x512/16 colors)\n", prog_name);
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Current CRTMOD is %d.\n", _iocs_crtmod(-1));
    return 0;
  }
  if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
    print_usage("CRTMOD.X");
    return 0;
  }
  int crtmod_value = -1;
  if ((sscanf(argv[1], "%d", &crtmod_value) != 1) || (crtmod_value < 0) || (crtmod_value > 255)){
    printf("Invalid input. Please enter a valid number.\n");
    return 1;
  }
  int old_crtmod = _iocs_crtmod(crtmod_value);
  printf("CRTMOD has been changed from %d to %d.\n", old_crtmod, crtmod_value);
}
