/**************************************************************/
/* Program:       exercise2 Date:                             */
/* Authors:Diego Rodriguez Ortiz y Alejandro Garcia Hernando  */
/*                                                            */
/* Program that writes in a file the average times            */
/* of the search algorithm                                    */
/*                                                            */
/* Input: Command line                                        */
/* -num_min: minimum number of elements in the table          */
/* -num_max: maximum number of elements in the table          */
/* -incr: increment                                           */
/* -fkeys: number of keys to search                           */
/* -numP: Introduce the number of permutations to average     */
/* -outputFile: Name of the output file                       */
/*                                                            */
/* Output: 0 if there was an error                            */
/*        -1 otherwise                                        */
/**************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "permutations.h"
#include "search.h"
#include "times.h"
#define Name31 "Lin_Search_Uniform_KeyPruebas.log"
#define Name32 "Lin_Auto_Search_Uniform_KeyPruebas.log"
#define Name33 "Bin_Search_Uniform_KeyPruebas.log"
#define Name34 "Lin_Search_Potential_KeyPruebas.log"
#define Name35 "Lin_Auto_Search_Potential_KeyPruebas.log"
#define Name36 "Bin_Search_Potential_KeyPruebas.log"

#define Name1 "Lin_Search_Uniform_KeyN_times=1.log"
#define Name2 "Lin_Auto_Search_Uniform_KeyN_times=1.log"
#define Name3 "Bin_Search_Uniform_KeyN_times=1.log"
#define Name4 "Lin_Search_Potential_KeyN_times=1.log"
#define Name5 "Lin_Auto_Search_Potential_KeyN_times=1.log"
#define Name6 "Bin_Search_Potential_KeyN_times=1.log"

#define Name11 "Lin_Search_Uniform_KeyN_times=100.log"
#define Name12 "Lin_Auto_Search_Uniform_KeyN_times=100.log"
#define Name13 "Bin_Search_Uniform_KeyN_times=100.log"
#define Name14 "Lin_Search_Potential_KeyN_times=100.log"
#define Name15 "Lin_Auto_Search_Potential_KeyN_times=100.log"
#define Name16 "Bin_Search_Potential_KeyN_times=100.log"

#define Name21 "Lin_Search_Uniform_KeyN_times=1000.log"
#define Name22 "Lin_Auto_Search_Uniform_KeyN_times=1000.log"
#define Name23 "Bin_Search_Uniform_KeyN_times=1000.log"
#define Name24 "Lin_Search_Potential_KeyN_times=1000.log"
#define Name25 "Lin_Auto_Search_Potential_KeyN_times=1000.log"
#define Name26 "Bin_Search_Potential_KeyN_times=1000.log"
int main(int argc, char** argv)
{
  int i, num_min,num_max,incr,n_times,n_perms=100,n;
  char name[256];
  short ret;
 
  srand(time(NULL));

  if (argc != 11) {
    fprintf(stderr, "Error in the input parameters:\n\n");
    fprintf(stderr, "%s -num_min <int> -num_max <int> -incr <int>\n", argv[0]);
    fprintf(stderr, "\t\t -n_keys <int> -n_times <int> -outputFile <string> \n");
    fprintf(stderr, "Where:\n");
    fprintf(stderr, "-num_min: minimum number of elements of the table\n");
    fprintf(stderr, "-num_max: maximum number of elements of the table\n");
    fprintf(stderr, "-incr: increment\n");
    fprintf(stderr, "-n_times: number of times each key is searched\n");
    fprintf(stderr, "-outputFile: Output file name\n");
    exit(-1);
  }

  printf("Practice number 3, section 2\n");
  printf("Done by: Your names\n");
  printf("Group: Your group\n");

  /* check the command line */
  for(i = 1; i < argc ; i++) {
    if (strcmp(argv[i], "-num_min") == 0) {
      num_min = atoi(argv[++i]);
    } else if (strcmp(argv[i], "-num_max") == 0) {
      num_max = atoi(argv[++i]);
    } else if (strcmp(argv[i], "-incr") == 0) {
      incr = atoi(argv[++i]);
    } else if (strcmp(argv[i], "-n_times") == 0) {
      n_times = atoi(argv[++i]);
    } else if (strcmp(argv[i], "-outputFile") == 0) {
      strcpy(name, argv[++i]);
    } else {
      fprintf(stderr, "Parameter %s is invalid\n", argv[i]);
      exit(-1);
    }
  }
  

  /*calculamos los tiempos */
  /*Para n_times =1 en principio*/
  if(n_times==1){
  /*calculamos los tiempos */
  /*Para n_times =1 en principio*/
    n_times=1;
    ret = generate_search_times_aux(lin_search, uniform_key_generator, NOT_SORTED, 
                                  Name1, num_min, num_max, incr, n_times,1);
    if (ret == ERR) { 
      printf("Error in function generate_search_times_aux\n");
      exit(-1);
    }
    printf("Lin search  uniform cheack\n");
    ret = generate_search_times_aux(lin_auto_search, uniform_key_generator, NOT_SORTED, 
                                  Name2, num_min, num_max, incr, n_times,1);
    if (ret == ERR) { 
      printf("Error in function generate_search_times_aux\n");
      exit(-1);
    }
    printf("Lin auto search  ntimes=1 uniform cheack\n");

    ret = generate_search_times_aux(bin_search, uniform_key_generator,SORTED, 
                                  Name3, num_min, num_max, incr, n_times,1);
    if (ret == ERR) { 
      printf("Error in function generate_search_times_aux\n");
      exit(-1);
    }
      printf("Bin search ntimes=1 uniform cheack\n");

    ret = generate_search_times_aux(lin_search, potential_key_generator,NOT_SORTED, 
                                  Name4, num_min, num_max, incr, n_times,n_perms);
    if (ret == ERR) { 
      printf("Error in function generate_search_times_aux\n");
      exit(-1);
    }
    printf("Lin search ntimes=1  potential cheack\n");

    ret = generate_search_times_aux(lin_auto_search, potential_key_generator,NOT_SORTED, 
                                  Name5, num_min, num_max, incr, n_times,n_perms);
    if (ret == ERR) { 
      printf("Error in function generate_search_times_aux\n");
      exit(-1);
    }
      printf("Lin auto search ntimes=1  potential cheack\n");


    ret = generate_search_times_aux(bin_search, potential_key_generator,SORTED, 
                                  Name6, num_min, num_max, incr, n_times,1);
    if (ret == ERR) { 
      printf("Error in function generate_search_times_aux\n");
      exit(-1);
    }
      printf("Bin search ntimes=1 potential cheack\n");

    /*Para n_times 100*/
    n_times=100;
    ret = generate_search_times_aux(lin_search, uniform_key_generator, NOT_SORTED, 
                                  Name11, num_min, num_max, incr, n_times,1);
    if (ret == ERR) { 
      printf("Error in function generate_search_times_aux\n");
      exit(-1);
    }
    printf("Lin search ntimes=100 uniform cheack\n");
    ret = generate_search_times_aux(lin_auto_search, uniform_key_generator, NOT_SORTED, 
                                  Name12, num_min, num_max, incr, n_times,1);
    if (ret == ERR) { 
      printf("Error in function generate_search_times_aux\n");
      exit(-1);
    }
    printf("Lin auto search  ntimes=100 uniform cheack\n");

    ret = generate_search_times_aux(bin_search, uniform_key_generator,SORTED, 
                                  Name13, num_min, num_max, incr, n_times,1);
    if (ret == ERR) { 
      printf("Error in function generate_search_times_aux\n");
      exit(-1);
    }
      printf("Bin search ntimes=100 uniform cheack\n");

    ret = generate_search_times_aux(lin_search, potential_key_generator,NOT_SORTED, 
                                  Name14, num_min, num_max, incr, n_times,n_perms);
    if (ret == ERR) { 
      printf("Error in function generate_search_times_aux\n");
      exit(-1);
    }
    printf("Lin search ntimes=100  potential cheack\n");

    ret = generate_search_times_aux(lin_auto_search, potential_key_generator,NOT_SORTED, 
                                  Name15, num_min, num_max, incr, n_times,n_perms);
    if (ret == ERR) { 
      printf("Error in function generate_search_times_aux\n");
      exit(-1);
    }
      printf("Lin auto search ntimes=100  potential cheack\n");


    ret = generate_search_times_aux(bin_search, potential_key_generator,SORTED, 
                                  Name16, num_min, num_max, incr, n_times,1);
    if (ret == ERR) { 
      printf("Error in function generate_search_times_aux\n");
      exit(-1);
    }
      printf("Bin search ntimes=100 potential cheack\n");

    /*Para n_times 1000 */
    n_times=1000;
      ret = generate_search_times_aux(lin_search, uniform_key_generator, NOT_SORTED, 
                                  Name21, num_min, num_max, incr, n_times,1);
    if (ret == ERR) { 
      printf("Error in function generate_search_times_aux\n");
      exit(-1);
    }
      printf("Lin search ntimes=1000 uniform cheack\n");

    ret = generate_search_times_aux(lin_auto_search, uniform_key_generator, NOT_SORTED, 
                                  Name22, num_min, num_max, incr, n_times,1);
    if (ret == ERR) { 
      printf("Error in function generate_search_times_aux\n");
      exit(-1);
    }
      printf("Lin auto search  ntimes=1000 uniform cheack\n");

    ret = generate_search_times_aux(bin_search, uniform_key_generator,SORTED, 
                                  Name23, num_min, num_max, incr, n_times,1);
    if (ret == ERR) { 
      printf("Error in function generate_search_times_aux\n");
      exit(-1);
    }
        printf("Bin search ntimes=1000 uniform cheack\n");

    ret = generate_search_times_aux(lin_search, potential_key_generator,NOT_SORTED, 
                                  Name24, num_min, num_max, incr, n_times,n_perms);
    if (ret == ERR) { 
      printf("Error in function generate_search_times_aux\n");
      exit(-1);
    }
      printf("Lin search ntimes=1000  potential cheack\n");

    ret = generate_search_times_aux(lin_auto_search, potential_key_generator,NOT_SORTED, 
                                  Name25, num_min, num_max, incr, n_times,n_perms);
    if (ret == ERR) { 
      printf("Error in function generate_search_times_aux\n");
      exit(-1);
    }
        printf("Lin auto search ntimes=1000  potential cheack\n");

    ret = generate_search_times_aux(bin_search, potential_key_generator,SORTED, 
                                  Name26, num_min, num_max, incr, n_times,1);
    if (ret == ERR) { 
      printf("Error in function generate_search_times_aux\n");
      exit(-1);
    }
        printf("Bin search ntimes=1000 potential cheack\n");


    printf("Correct output \n");
  }else if(n_times==2){
      n_times=1;
      ret = generate_search_times(lin_auto_search, potential_key_generator,NOT_SORTED, 
                                    Name15, num_min, num_max, incr, n_times);
      if (ret == ERR) { 
        printf("Error in function generate_search_times\n");
        exit(-1);
      }
        printf("Lin auto search ntimes=1  potential cheack\n");


      ret = generate_search_times(bin_search, potential_key_generator,SORTED, 
                                    Name16, num_min, num_max, incr, n_times);
      if (ret == ERR) { 
        printf("Error in function generate_search_times\n");
        exit(-1);
      }
        printf("Bin search ntimes=1 potential cheack\n");
      /*Para n_times 100*/
      n_times=100;
      ret = generate_search_times(lin_search, uniform_key_generator, NOT_SORTED, 
                                    Name11, num_min, num_max, incr, n_times);
      if (ret == ERR) { 
        printf("Error in function generate_search_times\n");
        exit(-1);
      }
      printf("Lin search ntimes=100 uniform cheack\n");
      ret = generate_search_times(lin_auto_search, uniform_key_generator, NOT_SORTED, 
                                    Name12, num_min, num_max, incr, n_times);
      if (ret == ERR) { 
        printf("Error in function generate_search_times\n");
        exit(-1);
      }
      printf("Lin auto search  ntimes=100 uniform cheack\n");

      ret = generate_search_times(bin_search, uniform_key_generator,SORTED, 
                                    Name13, num_min, num_max, incr, n_times);
      if (ret == ERR) { 
        printf("Error in function generate_search_times\n");
        exit(-1);
      }
        printf("Bin search ntimes=100 uniform cheack\n");

      ret = generate_search_times(lin_search, potential_key_generator,NOT_SORTED, 
                                    Name14, num_min, num_max, incr, n_times);
      if (ret == ERR) { 
        printf("Error in function generate_search_times\n");
        exit(-1);
      }
      printf("Lin search ntimes=100  potential cheack\n");

      ret = generate_search_times(lin_auto_search, potential_key_generator,NOT_SORTED, 
                                    Name15, num_min, num_max, incr, n_times);
      if (ret == ERR) { 
        printf("Error in function generate_search_times\n");
        exit(-1);
      }
        printf("Lin auto search ntimes=100  potential cheack\n");


      ret = generate_search_times(bin_search, potential_key_generator,SORTED, 
                                    Name16, num_min, num_max, incr, n_times);
      if (ret == ERR) { 
        printf("Error in function generate_search_times\n");
        exit(-1);
      }
        printf("Bin search ntimes=100 potential cheack\n");

      /*Para n_times 1000 */
      n_times=1000;
        ret = generate_search_times(lin_search, uniform_key_generator, NOT_SORTED, 
                                    Name21, num_min, num_max, incr, n_times);
      if (ret == ERR) { 
        printf("Error in function generate_search_times\n");
        exit(-1);
      }
        printf("Lin search ntimes=1000 uniform cheack\n");

      ret = generate_search_times(lin_auto_search, uniform_key_generator, NOT_SORTED, 
                                    Name22, num_min, num_max, incr, n_times);
      if (ret == ERR) { 
        printf("Error in function generate_search_times\n");
        exit(-1);
      }
        printf("Lin auto search  ntimes=1000 uniform cheack\n");

      ret = generate_search_times(bin_search, uniform_key_generator,SORTED, 
                                    Name23, num_min, num_max, incr, n_times);
      if (ret == ERR) { 
        printf("Error in function generate_search_times\n");
        exit(-1);
      }
          printf("Bin search ntimes=1000 uniform cheack\n");

      ret = generate_search_times(lin_search, potential_key_generator,NOT_SORTED, 
                                    Name24, num_min, num_max, incr, n_times);
      if (ret == ERR) { 
        printf("Error in function generate_search_times\n");
        exit(-1);
      }
        printf("Lin search ntimes=1000  potential cheack\n");

      ret = generate_search_times(lin_auto_search, potential_key_generator,NOT_SORTED, 
                                    Name25, num_min, num_max, incr, n_times);
      if (ret == ERR) { 
        printf("Error in function generate_search_times\n");
        exit(-1);
      }
          printf("Lin auto search ntimes=1000  potential cheack\n");

      ret = generate_search_times(bin_search, potential_key_generator,SORTED, 
                                    Name26, num_min, num_max, incr, n_times);
      if (ret == ERR) { 
        printf("Error in function generate_search_times\n");
        exit(-1);
      }
          printf("Bin search ntimes=1000 potential cheack\n");


      printf("Correct output \n");
  }else{
      n_perms=100;
      n=10;
      ret = generate_search_times_aux(lin_search, uniform_key_generator, NOT_SORTED, 
                                    Name31, num_min, num_max, incr, n ,1);
      if (ret == ERR) { 
        printf("Error in function generate_search_times\n");
        exit(-1);
      }
      printf("Lin search pruebas uniform cheack\n");
      ret = generate_search_times_aux(lin_auto_search, uniform_key_generator, NOT_SORTED, 
                                    Name32, num_min, num_max, incr, n ,1);
      if (ret == ERR) { 
        printf("Error in function generate_search_times\n");
        exit(-1);
      }
      printf("Lin auto search  pruebas uniform cheack\n");

      ret = generate_search_times_aux(bin_search, uniform_key_generator,SORTED, 
                                    Name33, num_min, num_max, incr, n_times,1);
      if (ret == ERR) { 
        printf("Error in function generate_search_times\n");
        exit(-1);
      }
      printf("Bin search pruebas uniform cheack\n");  

      ret = generate_search_times_aux(lin_search, potential_key_generator,NOT_SORTED, 
                                    Name34, num_min, num_max, incr, n,1);
      if (ret == ERR) { 
        printf("Error in function generate_search_times\n");
        exit(-1);
      } 
      printf("Lin search pruebas pruebas potential cheack\n");

      ret = generate_search_times_aux(lin_auto_search, potential_key_generator,NOT_SORTED, 
                                    Name35, num_min, num_max, incr, n_times,1);
      if (ret == ERR) { 
        printf("Error in function generate_search_times\n");
        exit(-1);
      }
        printf("Lin auto search pruebas  potential cheack\n");


      ret = generate_search_times_aux(bin_search, potential_key_generator,SORTED, 
                                    Name36, num_min, num_max, incr, n_times,1);
      if (ret == ERR) { 
        printf("Error in function generate_search_times\n");
        exit(-1);
      }
        printf("Bin search pruebas potential cheack\n");
        printf("Correct output");
  }
  return 0;
}

