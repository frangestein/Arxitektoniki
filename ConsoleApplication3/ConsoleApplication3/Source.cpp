#include <stdio.h>
#include <stdlib.h>

// dilosi predictors
char predictor2bit(char pred,int s);
char predictor1bit(char pred,int s);


	FILE *output1bit;     
    FILE *output2bit;
	FILE *outputtest;

	float sum_of_hits_1bit = 0;
	float sum_of_hits_2bit = 0;
	float sum_of_klisis_1b1t = 0;
	float sum_of_klisis_2bit = 0;

int main(){
    // diktes se arxia
	FILE *input;



    // arxikopiisi kai dilosi metavliton
	int k = 0;
	int	n = 1;
	int j = 0;
	int i = 0;
	int right1 =0;
	int right2 = 0;
	int counter = 0;
	int whileout = 0;
	int first = 0;
	int same = 0;
	int counter01 = 1;
	int sum_branches = 0;

	float success_1bit;
	float success_2bit;

	char ch = 0;
	char prediction1_1bit='T';
	char prediction2_1bit='T';
	char prediction1_2bit='T';
	char prediction2_2bit='T';
	
	char pinakas[50][9];
	char pinakas_temp[3][9];
	
	//anigma arxion
	input=fopen("input.txt","r");
	if (!input)
    {
        printf("Can not find input file!!\n");    
		getchar();
        return 0;
    }
	output1bit=fopen("output1bit.txt","w");
	output2bit=fopen("output2bit.txt","w");
	outputtest=fopen("outputtest.txt","w");
	
	// while atelioto mexri na vro EOF
	
	while (whileout == 0)
    {   
        // while mexri na vro 3is diaforetikes diefthinsis
		while(n!=3)
		{	
            //for gia to gemisma tou pinaka kai ton elexo ton stixion p lamvano apo to arxio
			for(i = 0; i < 9;i++) 
			{ 
                ch=fgetc(input);
				if(ch==EOF)
				{
					printf("Teliose to arxio");
					getchar();
					whileout = 1;
					n=3;

				}
				else
				{
				if(ch!='A' && ch!='B' && ch!='C' && ch!='D' && ch!='E' && ch!='F' && ch!='0' && ch!='1' && ch!='2' && ch!='3' && ch!='4' && ch!='5' && ch!='6' && ch!='7' && ch!='8' && ch!='9' && ch!='\n')
				{
					printf( "Unknow character input in file!!!\n" );
					getchar();
					return (0);
				}
				else
				{
				    if( first == 0)
				    {
                        pinakas_temp[0][i] = ch;
                        pinakas[0][i] = ch;
                    }
                    else

                    {
                        pinakas[j][i] = ch;
                    }
				}

				}

			}//telos for///// sosto---------------------------------

			
				// metafora metavliton ston pinaka temporary gia na gnorizo ti vlepo
				// metrisi ton branches
				// kathos elexos ton timon me ton temp gia ton elexo gia na stamatisi to while
				if (n == 1 && first == 1)
				{
                          for(i = 0; i < 8; i++)
			              {
                           if(pinakas[j][i] == pinakas_temp[0][i])
                           {
                                            right1++;
                           }
                           }
                           if (right1 != 8)
                           {
                                      for(i=0;i<9;i++)
                                      {
                                                      pinakas_temp[1][i] = pinakas[j][i];
                                      }
                                      n++;
									  sum_branches++;
                           } 
                 }
                 else
                 {
                     if(n==2)
                     {
                             for(i = 0; i < 8; i++)
			                 {
                             if(pinakas[j][i] == pinakas_temp[0][i])
                             {
                                            right1++;
                             }
                             if(pinakas[j][i] == pinakas_temp[1][i])
                             {
                                              right2++;
                             }
                             
                             }
                             
                             if((right1 != 8) && (right2 != 8))
                             {
                                       for(i = 0;i < 9;i++)
                                       {
                                              pinakas_temp[2][i] = pinakas[j][i];
                                       }
                                       n++;
                                       sum_branches++;
                                                       
                             }                              
                     }
                 }

		
				// edo vriskome sto while (n!=3)
				right1 = 0;
				right2 = 0;
				first = 1;
				j++;
		}//telos while(n!=3
		// edo p pinakas mou ine teliomenos me 2 sira apo 2 diaforerikes diefthinsis kai sto telos me mia  3i


        // elexos gia to an oi pinakes gemisan ok.
	
		for(k = 0;k < 3; k++)
		{
              for(i = 0;i < 9; i++)
              {
				  fprintf(outputtest,"%c" ,pinakas_temp[k][i]);
			  }
		}

		fprintf(outputtest,"\n");
		fprintf(outputtest,"\n");
		fprintf(outputtest,"\n");
		fprintf(outputtest,"\n");


		for(k = 0;k < 50; k++)
		{
              for(i = 0;i < 9; i++)
              {
				  fprintf(outputtest,"%c",pinakas[k][i]);
			  }
		}

		fprintf(outputtest,"\n");

		
		//predictors place calling
		
		for(k = 0;k < j-1; k++)
		{
              for(i = 0;i < 8; i++)
              {
                    if(pinakas[k][i] == pinakas[k+1][i])
                    {
                                     counter++;
                    }
              }
              
              if(counter == 8)
              {
                         same = 1;
              }
              else
              {
                         same = 0;
              }
              
              if(same == 1 && counter01 == 1)
              {
					 printf("prediction1_2bit counter == 1%c\n",prediction1_2bit);
                      prediction1_1bit= predictor1bit( prediction1_1bit, same);
                      prediction1_2bit = predictor2bit( prediction1_2bit, same);
					  counter01=1;
              }
              else
              {
                      if( same == 1 && counter01 == 2)
                      {
						  //printf("prediction2_1bit counter == 2%c\n",prediction2_1bit);
						  printf("prediction2_2bit counter == 2%c\n",prediction2_2bit);
                          prediction2_1bit = predictor1bit( prediction2_1bit, same);
                          prediction2_2bit = predictor2bit( prediction2_2bit, same);
						  counter01=2;
                      }
                      else
                      {
                          if( same == 0 && counter01 == 1 )
                          {
							  //printf("prediction1_1bit counter == 1 going 2 %c\n",prediction1_1bit);
							  printf("prediction1_2bit counter == 1 going 2 %c\n",prediction1_2bit);
                              prediction1_1bit = predictor1bit( prediction1_1bit, same);
                              prediction1_2bit = predictor2bit( prediction1_2bit, same);
                              counter01 = 2;
                          }
                          else
                          {
                              if( same == 0 && counter01 == 2 )
                              {
								  //printf("prediction2_1bit counter == 2 is going 1 %c\n",prediction2_1bit);
						          printf("prediction2_2bit counter == 2 is going 1 %c\n",prediction2_2bit);
                                  prediction2_1bit = predictor1bit( prediction2_1bit, same);
                                  prediction2_2bit = predictor2bit( prediction2_2bit, same);
                                  counter01 = 1;
                              }
                          }
					  }
              }
              counter = 0;
              
              
        }//predictor calling ending */
        
        
        // anathesi tis tritis diefthinsis p den eleksa stin proti thesi tou kenourgiou m pinaka
		// kai i anathesi tis tritis diefthinsis gia 1 ston pinaka pinaka_temp
        for(i = 0;i < 9; i++)
        {
              pinakas[0][i] = pinakas_temp[2][i];
			  pinakas_temp[0][i] = pinakas_temp[2][i];
        }


        //arxikopiisi timon gia ton kenourgio pinaka
        n = 1;
        counter01 = 1;
        j = 1;
        
       	 prediction1_1bit='T';
         prediction2_1bit='T';
         prediction1_2bit='T';
         prediction2_2bit='T';
        
	    }

	sum_branches= sum_branches + 1; //giati den to perni stin proti timi p perno stin arxi
	fprintf(output1bit,"hit: %f\n",sum_of_hits_1bit);
	fprintf(output1bit,"klisis: %f\n",sum_of_klisis_1b1t);
	success_1bit = sum_of_hits_1bit / sum_of_klisis_1b1t;
	fprintf(output1bit,"Success rate:%f\n",success_1bit);
	success_1bit = success_1bit * 100;
	fprintf(output1bit,"Success rate:%f\n",success_1bit);
	fprintf(output1bit,"This is the number of branches %d",sum_branches);

	fprintf(output2bit,"hit: %f\n",sum_of_hits_2bit);
	fprintf(output2bit,"klisis: %f\n",sum_of_klisis_2bit);
	success_2bit = sum_of_hits_2bit / sum_of_klisis_2bit;
	fprintf(output2bit,"Success rate:%f\n",success_2bit);
	success_2bit = success_2bit * 100;
	fprintf(output2bit,"Success rate:%f\n",success_2bit);
    fprintf(output2bit,"This is the number of branches %d",sum_branches);
	
	fclose(input);
	fclose(output1bit);
	fclose(output2bit);
	fclose(outputtest);

	getchar();

	
}



char predictor2bit(char pred,int s)
{
	
     char nextpred;
     sum_of_klisis_2bit++;

     if (pred == 'T' && s == 1 )
	{
        fprintf(output2bit,"Hit\n");
		sum_of_hits_2bit++;
        nextpred = 'T';
    }
    else
    {
        if (pred == 'T' && s == 0)
         {
         fprintf(output2bit,"Miss\n");
         nextpred = 't';
         }
         else
         {
              if (pred == 'F' && s == 0)
              {
              fprintf(output2bit,"Hit\n");
			  sum_of_hits_2bit++;
              nextpred = 'F';
              }
              else
              {
                   if (pred == 'F' && s == 1)
                   {
                   fprintf(output2bit,"Miss\n");
                   nextpred = 'f';
                   }
                   else
                   {
                       
                        if (pred == 't' && s == 1)
                        {
                        fprintf(output2bit,"Hit\n");
			            sum_of_hits_2bit++;
                        nextpred = 'T';
                        }
                        else
                        {
                      		 if (pred == 't' && s == 0)
						 	 {
                             fprintf(output2bit,"Miss\n");
                             nextpred = 'F';
                             }
                             else
                             {
                                  if (pred == 'f' && s == 1)
                                  {
                                  fprintf(output2bit,"Miss\n");
                                  nextpred = 'T';
                                  }
                                  else
                                  {
                                       if (pred == 'f' && s == 0)
									   {
                                       fprintf(output2bit,"Hit\n");
									   sum_of_hits_2bit++;
                                       nextpred = 'F';
                                       }
                                  }
                              }
                         }
                    }
               }
          }
	 }
    

	return (nextpred);
          
}



char predictor1bit(char pred,int s)
{
	
	char nextpred;
    sum_of_klisis_1b1t++;
    if(pred == 'T' && s == 1 ){
            fprintf(output1bit,"Hit\n");
			sum_of_hits_1bit++;
            nextpred = 'T';
    }
    else if (pred == 'T' && s == 0){
         fprintf(output1bit,"Miss\n");
         nextpred = 'F';
         }
         else if (pred == 'F' && s == 0){
              fprintf(output1bit,"Hit\n");
			  sum_of_hits_1bit++;
              nextpred = 'F';
              }
              else if (pred == 'F' && s == 1){
                   fprintf(output1bit,"Miss\n");
                   nextpred = 'T';
                   }
	return (nextpred);
}