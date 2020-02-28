#include <unistd.h>
#include <stdio.h>
#include <err.h>

int
main(){
  /* Give program read access only to /home */
  if(unveil("/home/", "r") == -1)
    err(1, "unveil");

  /* Declare that this program only uses stdio */
  if(pledge("stdio", NULL) == -1)
    err(1, "pledge");

  /* actual hello world */
  printf("Hello, World!\n");
  return 0;
}
