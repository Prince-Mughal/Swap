/* 
   Twitter: @PrinceMughal_ 
   Warmly Welcome at:
   Email: princeb92@hotmail.com
   NICK: Prince Mughal
   PROJECT: Greent Computer Team (GCT)
   OS/LANGUAGE:LinuxC 
   Achieved: A generic function to Swap Numbers or Strings
   TimeStamp: 20-AUG-2017 ; 2:39:35 AM PST MONDAY 
   			at LAHORE PUNJAB PAKISTAN

   */

#include <stdio.h> /* fprintf(), fscanf(), getchar */
#include <stdlib.h>/* malloc(), free() */
#include <string.h>/* memcpy() */

void swap(void*,void*,const size_t);
void FREE(void);

int main(void){

    /* Swap Two Integers */
    int inum1 = 0;
    int inum2 = 0;
    fprintf(stdout,"Enter an Integer Number: ");
    fscanf(stdin,"%d",&inum1);
    fprintf(stdout,"Enter an Other Integer Number: ");
    fscanf(stdin,"%d",&inum2);
    swap((void*)&inum1,(void*)&inum2,sizeof(int));
    fprintf(stdout,"inum1=%d : inum2=%d \n",inum1,inum2);


    /* Swap Two Floats */
    float fnum1 = 0;
    float fnum2 = 0;
    fprintf(stdout,"Enter a Float Number: ");
    fscanf(stdin,"%f",&fnum1);
    fprintf(stdout,"Enter an Other Float Number: ");
    fscanf(stdin,"%f",&fnum2);
    swap((void*)&fnum1,(void*)&fnum2,sizeof(float));
    fprintf(stdout,"fnum1=%f : fnum2=%f \n",fnum1,fnum2);
    /* Clear Input Buffer to Store String */
    FREE();
    /* Swap Two Strings */
    size_t size = 24;
    char *sMsg1 = (char*)malloc(size);
    char *sMsg2 = (char*)malloc(size);
     
    fprintf(stdout,"Enter a MSG1: ");
    getline(&sMsg1,&size,stdin);
    fprintf(stdout,"Enter a MSG2: ");
    getline(&sMsg2,&size,stdin);
    swap((void*)sMsg1,(void*)sMsg2, size); // Correction
    sMsg1[strlen(sMsg1)-1] = '\0';
    sMsg2[strlen(sMsg2)-1] = '\0';
    fprintf(stdout,"MSG1=%s : MSG2=%s \n",sMsg1,sMsg2);
    free(sMsg1);
    free(sMsg2);
 


 return 0; }
 /* A generic function to Swap two Numbers or Strings */
 void swap(void* iData1,void* iData2, const size_t size){

     /* Allocate a piece of memory */
     void* tmp = (void*)malloc(size);
     /* Check Memory Allocation */
     if( tmp == NULL)
         fprintf(stderr,"Error: Couldn't Allocate Memory.\n");
     /* copy iData1 to tmp */
     memcpy(tmp,iData1,size);
     /* copy iData2 to iData1 */
     memcpy(iData1,iData2,size);
     /* copy tmp to iData2 */
     memcpy(iData2,tmp,size);
     /*free Memory Area*/
     free(tmp);}
    /* A Function to Flush out all input Buffer */
   void FREE(void){
        /* to Hold a Garbage Character */
        char c;
        /* Read until NEWLINE captured */
        while((c = getchar()) && (c != '\n'));
        /* return to called Place*/
   return;}
