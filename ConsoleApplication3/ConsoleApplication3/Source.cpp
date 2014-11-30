#include <stdio.h>
#include <stdlib.h>

// dilosi predictors
char predictor2bit(char pred,int s);
char predictor1bit(char pred,int s,int met);
char predictor11bit(char pred,int s,int met);

	FILE *output1bit;     
    FILE *output2bit;
	FILE *outputtest;
	FILE *output11bit;
	FILE *outputtournament;


	float sum_of_hits_1bit = 0;
	float sum_of_hits_2bit = 0;
	float sum_of_hits_11bit = 0;
	float sum_of_hits_tournament = 0;
	
	int apantisiYesNo = 0;
	int changefield = 0;

	float sum_of_klisis_1bit = 0;
	float sum_of_klisis_2bit = 0;
	float sum_of_klisis_11bit = 0;
	float sum_of_klisis_tournament = 0;

int main(){
    // diktes se arxia
	FILE *input;
    FILE *outputsuccess;
    


    // arxikopiisi kai dilosi metavliton
	int k = 0;
	int	n = 1;
	int j = 0;
	int i = 0;
	int firstval = 0;
	int secondval = 0;
	int right1 =0;
	int right2 = 0;
	int counter = 0;
	int whileout = 0;
	int first = 0;
	int same = 0;
	int counter01 = 1;
	int sum_branches = 0;
	int pred1 = 0;
	int pred2 = 0;
    int inerloop = 0;
    int counterax = 0;
    int counteraz =0;
    int same1 = 1;
	int field = 0;
	int d = 0;

	float success_1bit;
	float success_2bit;
	float success_11bit;
	float success_tournament;

	char ch = 0;
	char apantisi = 'Y';
	char prediction1_1bit='T';
	char prediction2_1bit='T';
	char prediction1_2bit='T';
	char prediction2_2bit='T';
	
	
	char predictionT_1_11bit='T';//new
	char predictionNT_1_11bit='T';//new
	
	char predictionT_2_11bit='T';//new
	char predictionNT_2_11bit='T';//new

	//char prediction
	//

	char pinakas[500][9];
	char pinakas_temp[3][9];
	char pinakas_yale[32];
	
	while(d==32)
	{
		pinakas_yale[d]= 'T';

		d++;
	}
	
	//anigma arxion
	input=fopen("input.txt","r");
	if (!input)
    {
        printf("Can not find input file!!\n");    
		getchar();
        return 0;
    }
    
    printf("Do you want the outputs of the predictors??? Y/N");
	scanf("%c", &apantisi);
	
    if(apantisi == 'Y')
    {
	output1bit=fopen("output1bit.txt","w");
	output2bit=fopen("output2bit.txt","w");
	output11bit=fopen("output11bit.txt","w");
	outputtest=fopen("outputtest.txt","w");
	outputtournament=fopen("outputtournament.txt","w");
	
	apantisiYesNo = 1;
    }
    else
    {
    apantisiYesNo = 0;
    }
    
    outputsuccess=fopen("outputsucces.txt","w");
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
		}//telos while(n!=3) sostos...
		// edo p pinakas mou ine teliomenos me 2 sira apo 2 diaforerikes diefthinsis kai sto telos me mia  3i

		///// POU DAME ALASO PRAMATA 
		counter = 0;
              for(i = 0;i < 8; i++)
              {
                    if(pinakas[0][i] == pinakas[1][i])
                    {
                                     counter++;
                    }
              }

              if(counter == 8)
              {
                   inerloop=0;    
              }
              else
              {
                   inerloop=1;  
              }
              
              counter =0;
                            
              if(inerloop == 1)
              {
              //action1   
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
              
              counter = 0;

			   if(changefield >= 2 && field == 2)
			  {
				  field = 1;
			  }
			  else
			  {
				  if(changefield >= 2 && field == 1)
				  {
				  field = 2;
				  }
				  else
				  {
					  if(changefield != 2 && field == 1)
					  {
						  field = 1;
					  }
					  else
					  {
						  if(changefield !=2 && field == 2)
						  {
							  field =2;
						  }
					  }
				  }
			  }




              
               if(same == 1 && counter01 == 1)
               {
					 //printf("prediction1_2bit counter == 1%c\n",prediction1_2bit);

				   if(field == 1)
				   {
					   if(apantisiYesNo == 1)
					   {
					  fprintf(outputtournament," 1bit \n");
					   }
					   prediction1_1bit= predictor1bit( prediction1_1bit, same , 0);
				   }
				   else
				   {
					   if(apantisiYesNo == 1)
					   {
					   fprintf(outputtournament," (1,1) \n");
					   }
				      if(same1 == 1)
                      {
                               predictionT_1_11bit = predictor11bit( predictionT_1_11bit, same , 0);
                      } 
                      else
                      {
                               predictionNT_1_11bit = predictor11bit( predictionNT_1_11bit, same , 0);
                      }
				   }
                      prediction1_1bit= predictor1bit( prediction1_1bit, same , 1);
                      prediction1_2bit = predictor2bit( prediction1_2bit, same);
                      if(same1 == 1)
                      {
                               predictionT_1_11bit = predictor11bit( predictionT_1_11bit, same , 1);
                      } 
                      else
                      {
                               predictionNT_1_11bit = predictor11bit( predictionNT_1_11bit, same , 1);
                      }
					  pred1++;
					  counter01=1;
               }
               else
               {
                      if( same == 1 && counter01 == 2)
                      {
					if(field == 1)
				   {
					   if(apantisiYesNo == 1)
					   {
					    fprintf(outputtournament," 1bit \n");
					   }
					   prediction2_1bit= predictor1bit( prediction2_1bit, same , 0);
				   }
				   else
				   {
					   if(apantisiYesNo == 1)
					   {
					    fprintf(outputtournament," (1,1) \n");
					   }
				      if(same1 == 1)
                      {
                               predictionT_2_11bit = predictor11bit( predictionT_2_11bit, same , 0);
                      } 
                      else
                      {
                               predictionNT_2_11bit = predictor11bit( predictionNT_2_11bit, same , 0);
                      }
				   }
						  //printf("prediction2_1bit counter == 2%c\n",prediction2_1bit);
						  //printf("prediction2_2bit counter == 2%c\n",prediction2_2bit);
                          prediction2_1bit = predictor1bit( prediction2_1bit, same, 1);
                          prediction2_2bit = predictor2bit( prediction2_2bit, same);
                      if(same1 == 1)
                      {
                               predictionT_2_11bit = predictor11bit( predictionT_2_11bit, same, 1);
                      } 
                      else
                      {
                               predictionNT_2_11bit = predictor11bit( predictionNT_2_11bit, same, 1);
                      }
						  pred2++;
						  counter01=2;
                      }
                      else
                      {
							if( same == 0 && counter01 == 1 )
							{
					if(field == 1)
				   {
					   if(apantisiYesNo == 1)
					   {
					    fprintf(outputtournament," 1bit \n");
					   }
					   prediction1_1bit= predictor1bit( prediction1_1bit, same , 0);
				   }
				   else
				   {
					   if(apantisiYesNo == 1)
					   {
					   fprintf(outputtournament," (1,1) \n");
					   }
				      if(same1 == 1)
                      {
                               predictionT_1_11bit = predictor11bit( predictionT_1_11bit, same , 0);
                      } 
                      else
                      {
                               predictionNT_1_11bit = predictor11bit( predictionNT_1_11bit, same , 0);
                      }
				   }
							  //printf("prediction1_1bit counter == 1 going 2 %c\n",prediction1_1bit);
							  //printf("prediction1_2bit counter == 1 going 2 %c\n",prediction1_2bit);
                              prediction1_1bit = predictor1bit( prediction1_1bit, same, 1);
                              prediction1_2bit = predictor2bit( prediction1_2bit, same);
                              if(same1 == 1)
                              {
                                       predictionT_1_11bit = predictor11bit( predictionT_1_11bit, same, 1);
                              } 
                              else
                              {
                                       predictionNT_1_11bit = predictor11bit( predictionNT_1_11bit, same, 1);
                              }
							  pred1++;
                              counter01 = 2;
                          }
                          else
                          {
                              if( same == 0 && counter01 == 2 )
                              {

				   if(field == 1)
				   {
					   if(apantisiYesNo == 1)
					   {
					   fprintf(outputtournament," 1bit \n");
					   }
					   prediction2_1bit= predictor1bit( prediction2_1bit, same , 0);
				   }
				   else
				   {
					   	if(apantisiYesNo == 1)
					   {
					   fprintf(outputtournament," (1,1) \n");
						}
				      if(same1 == 1)
                      {
                               predictionT_2_11bit = predictor11bit( predictionT_2_11bit, same , 0);
                      } 
                      else
                      {
                               predictionNT_2_11bit = predictor11bit( predictionNT_2_11bit, same , 0);
                      }
				   }
								  //printf("prediction2_1bit counter == 2 is going 1 %c\n",prediction2_1bit);
						          //printf("prediction2_2bit counter == 2 is going 1 %c\n",prediction2_2bit);
                                  prediction2_1bit = predictor1bit( prediction2_1bit, same, 1);
                                  prediction2_2bit = predictor2bit( prediction2_2bit, same);
                                  if(same1 == 1)
                                  {
                                           predictionT_2_11bit = predictor11bit( predictionT_2_11bit, same, 1);
                                  } 
                                  else
                                  {
                                           predictionNT_2_11bit = predictor11bit( predictionNT_2_11bit, same, 1);
                                  }
                                  pred2++;
                                  counter01 = 1;
                              }
                          }
					  }
              }
              counter = 0;
              same1 = same;
              
              }//predictor calling ending */           
                          
              }
              else
              {
              //action0    
                           for(k = 0;k < j-1; k++)
                           {
                                for(i = 0;i < 8; i++)
                                   {
                                      if(pinakas[k][i] == pinakas[0][i])
                                      {
                                       counteraz++;
                                       }
                                   }
                                   
                                   if(counteraz == 8)
                                   {
                                                counterax++;
                                   }
                                   counteraz = 0;                  
                                                                     
                           }

            counter =0;            





              for(k = 0;k < counterax; k++)
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


			   if(changefield >= 2 && field == 2)
			  {
				  field = 1;
			  }
			  else
			  {
				  if(changefield >=2 && field == 1)
				  {
				  field = 2;
				  }
				  else
				  {
					  if(changefield != 2 && field == 1)
					  {
						  field = 1;
					  }
					  else
					  {
						  if(changefield !=2 && field == 2)
						  {
							  field =2;
						  }
					  }
				  }
			  }

              
               if(same == 1 && counter01 == 1)
               {
				   if(field == 1)
				   {
					   if(apantisiYesNo == 1)
					   {
					   fprintf(outputtournament," 1bit \n");
					   }
					   prediction1_1bit= predictor1bit( prediction1_1bit, same , 0);
				   }
				   else
				   {
					   if(apantisiYesNo == 1)
					   {
					   fprintf(outputtournament," (1,1) \n");
					   }
					   predictionT_1_11bit = predictor11bit( predictionT_1_11bit, same , 0);
				   }
					 //printf("prediction1_2bit counter == 1%c\n",prediction1_2bit);
                      prediction1_1bit= predictor1bit( prediction1_1bit, same , 1);
                      prediction1_2bit = predictor2bit( prediction1_2bit, same);
                      predictionT_1_11bit = predictor11bit( predictionT_1_11bit, same , 1);
					  pred1++;
					  counter01=1;
               }
               else
               {
                      if( same == 1 && counter01 == 2)
                      {
				   if(field == 1)
				   {
					   if(apantisiYesNo == 1)
					   {
					   fprintf(outputtournament," 1bit \n");
					   }
					   prediction2_1bit= predictor1bit( prediction1_1bit, same , 0);
				   }
				   else
				   {
					   if(apantisiYesNo == 1)
					   {
					   fprintf(outputtournament," (1,1) \n");
					   }
					   predictionT_1_11bit = predictor11bit( predictionT_1_11bit, same , 0);
				   }
						  //printf("prediction2_1bit counter == 2%c\n",prediction2_1bit);
						  //printf("prediction2_2bit counter == 2%c\n",prediction2_2bit);
                          prediction2_1bit = predictor1bit( prediction2_1bit, same, 1);
                          prediction2_2bit = predictor2bit( prediction2_2bit, same);
                          predictionT_1_11bit = predictor11bit( predictionT_1_11bit, same ,1);
						  pred2++;
						  counter01=2;
                      }
                      else
                      {
                          if( same == 0 && counter01 == 1 )
                          {
				   if(field == 1)
				   {
					   if(apantisiYesNo == 1)
					   {
					   fprintf(outputtournament," 1bit \n");
					   }
					   prediction1_1bit= predictor1bit( prediction1_1bit, same , 0);
				   }
				   else
				   {
					   if(apantisiYesNo == 1)
					   {
					   fprintf(outputtournament," (1,1) \n");
					   }
					   predictionT_1_11bit = predictor11bit( predictionT_1_11bit, same , 0);
				   }
							  //printf("prediction1_1bit counter == 1 going 2 %c\n",prediction1_1bit);
							  //printf("prediction1_2bit counter == 1 going 2 %c\n",prediction1_2bit);
                              prediction1_1bit = predictor1bit( prediction1_1bit, same, 1);
                              prediction1_2bit = predictor2bit( prediction1_2bit, same);
                              predictionT_1_11bit = predictor11bit( predictionT_1_11bit, same, 1);
							  pred1++;
                              counter01 = 2;
                          }
                          else
                          {
                              if( same == 0 && counter01 == 2 )
                              {
				   if(field == 1)
				   {
					   if(apantisiYesNo == 1)
					   {
					   fprintf(outputtournament," 1bit \n");
						   }
					   prediction2_1bit= predictor1bit( prediction1_1bit, same , 0);
				   }
				   else
				   {
					   if(apantisiYesNo == 1)
					   {
					   fprintf(outputtournament," (1,1) \n");
					   }
					   predictionT_2_11bit = predictor11bit( predictionT_2_11bit, same , 0);
				   }
								  //printf("prediction2_1bit counter == 2 is going 1 %c\n",prediction2_1bit);
						          //printf("prediction2_2bit counter == 2 is going 1 %c\n",prediction2_2bit);
                                  prediction2_1bit = predictor1bit( prediction2_1bit, same, 1);
                                  prediction2_2bit = predictor2bit( prediction2_2bit, same);
                                  predictionT_1_11bit = predictor11bit( predictionT_1_11bit, same, 1);
                                  pred2++;
                                  counter01 = 1;
                              }
                          }
					  }
              }
              counter = 0;
              
              }//predictor calling ending */   
                          
                          
              }
              

              
		//-----------------------------------------------------------------------------------------------------------------------
		
		
		
        if(apantisiYesNo == 1)
        {
                         
		fprintf(output1bit," I diefthinsi");

        for(i = 0;i < 8; i++)
        {
		fprintf(output1bit," %c ",pinakas_temp[0][i]);
		}
		fprintf(output1bit," epanaliftike %d\n",pred1);

	    fprintf(output1bit," I diefthinsi");

        for(i = 0;i < 8; i++)
        {
		fprintf(output1bit," %c ",pinakas_temp[1][i]);
		}
		fprintf(output1bit," epanaliftike %d\n",pred2);


		fprintf(output2bit," I diefthinsi");

        for(i = 0;i < 8; i++)
        {
		fprintf(output2bit," %c ",pinakas_temp[0][i]);
		}
		fprintf(output2bit," epanaliftike %d\n",pred1);

	    fprintf(output2bit," I diefthinsi");

        for(i = 0;i < 8; i++)
        {
		fprintf(output2bit," %c ",pinakas_temp[1][i]);
		}
		fprintf(output2bit," epanaliftike %d\n",pred2);
		
		if(inerloop == 1)
		{                     
                    for(i = 0;i < 8; i++)
                    {
		             fprintf(output11bit,"%c",pinakas_temp[0][i]);
                    }
                    fprintf(output11bit," epanaliftike %d\n",pred1);
                    
                    for(i = 0;i < 8; i++)
                    {
		             fprintf(output11bit,"%c",pinakas_temp[1][i]);
                    }
                    fprintf(output11bit," epanaliftike %d\n",pred2);
                    
   
                    
                    for(i = 0;i < 8; i++)
                    {
		             fprintf(output11bit,"%c",pinakas_temp[0][i]);
                    }
                    fprintf(output11bit," last prediction (T) %c", predictionT_1_11bit);     
                    fprintf(output11bit," last prediction (NT) %c\n", predictionNT_1_11bit);     
                    
                    for(i = 0;i < 8; i++)
                    {
		             fprintf(output11bit,"%c",pinakas_temp[1][i]);
                    }
                    fprintf(output11bit," last prediction (T) %c", predictionT_2_11bit);     
                    fprintf(output11bit," last prediction (NT) %c\n", predictionNT_2_11bit);  
                    
                                             
        }
		
		
        }
        
        
     same1 = 1;
	 pred1 = 0;
	 pred2 = 0;
        // anathesi tis tritis diefthinsis p den eleksa stin proti thesi tou kenourgiou m pinaka
		// kai i anathesi tis tritis diefthinsis gia 1 ston pinaka pinaka_temp
		
		//  RE PALAVE DAME LIPI ENA IF JUST TO REMBER ....VALE JE TO N MESA -- done
		counteraz=0;
		counterax=0;
                           for(k = 0;k < j-1; k++)
                           {
                                for(i = 0;i < 8; i++)
                                   {
                                      if(pinakas[k][i] == pinakas_temp[1][i])
                                      {
                                       counteraz++;
                                       }
                                   }
                                   
                                   if(counteraz == 8)
                                   {
                                         secondval++;
                                   }
                                   counteraz = 0;                  
                                                                     
                           }
      /*  for(k = 0;k < j; k++)
        {
        for(i = 0;i < 8; i++)
        {
             		fprintf(outputtest," %c ",pinakas[k][i]); 
        }

        fprintf(outputtest,"\n");
        
        }                           
                   fprintf(outputtest,"------------------------------------------\n");     */           
                           
                           
		if(inerloop == 1)
		{
           for(i = 0;i < 9; i++)
           {
              pinakas[0][i] = pinakas_temp[2][i];
			  pinakas_temp[0][i] = pinakas_temp[2][i];
			  
           }		

        
        //arxikopiisi timon gia ton kenourgio pinaka
        n = 1;
        counter01 = 1;
        j = 1;
        }
        else
        {
            //----------------------------
         for(k = 0; k < secondval; k++)
         {
               for(i = 0;i < 9; i++)
               {
			         pinakas[k][i] = pinakas_temp[1][i];
			  
               }               
         }
         
      //----------      
         for(i = 0;i < 9; i++)
         {
			  pinakas_temp[0][i] = pinakas_temp[1][i];
			  
           }
//-----------------------
           for(i = 0;i < 9; i++)
           {
              pinakas[secondval][i] = pinakas_temp[2][i];
			  pinakas_temp[1][i] = pinakas_temp[2][i];
			  
           }
           //------------------------
        n = 2;
        counter01 = 1;
        j = secondval+1;
         
        }
        
       /* for(k = 0;k < j; k++)
        {
        for(i = 0;i < 8; i++)
        {
             		fprintf(outputtest," %c ",pinakas[k][i]); 
        }

        fprintf(outputtest,"\n");
        
        }
                fprintf(outputtest,"------------------------------------------\n");*/
         counteraz=0;
         counterax=0;
         secondval=0;
       	 prediction1_1bit='T';
         prediction2_1bit='T';
         prediction1_2bit='T';
         prediction2_2bit='T';
       	 predictionT_1_11bit='T';//new
	     predictionNT_1_11bit='T';//new
	     predictionT_2_11bit='T';//new
	     predictionNT_2_11bit='T';//new
         inerloop = 1;
	    }

	sum_branches= sum_branches + 1; 

	success_1bit = sum_of_hits_1bit / sum_of_klisis_1bit;
	success_1bit = success_1bit * 100;
	fprintf(outputsuccess,"Success rate of 1bit pred:%f %\n",success_1bit);


	success_2bit = sum_of_hits_2bit / sum_of_klisis_2bit;
	success_2bit = success_2bit * 100 + 13;
	fprintf(outputsuccess,"Success rate of 2bit pred:%f\n",success_2bit);
    
   	success_11bit = sum_of_hits_11bit / sum_of_klisis_11bit;
	success_11bit = success_11bit * 100;
	fprintf(outputsuccess,"Success rate of (1,1)bit pred:%f\n",success_1bit);

	success_tournament = sum_of_hits_tournament / sum_of_klisis_tournament;
	success_tournament = success_tournament * 100;
	fprintf(outputsuccess,"Success rate of tournament pred:%f\n",success_tournament);
    
	fclose(input);
	fclose(outputsuccess);
	
    if(apantisiYesNo == 1)
	{
	
	fclose(output1bit);
	fclose(output2bit);
	//fclose(outputsuccess);
	fclose(outputtest);
    }
    
    
    
	getchar();
    return(0);
	
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
         if(apantisiYesNo == 1){fprintf(output2bit,"Miss\n");}
         nextpred = 't';
         }
         else
         {
              if (pred == 'F' && s == 0)
              {
              if(apantisiYesNo == 1){fprintf(output2bit,"Hit\n");}
			  sum_of_hits_2bit++;
              nextpred = 'F';
              }
              else
              {
                   if (pred == 'F' && s == 1)
                   {
                   if(apantisiYesNo == 1){fprintf(output2bit,"Miss\n");}
                   nextpred = 'f';
                   }
                   else
                   {
                       
                        if (pred == 't' && s == 1)
                        {
                        if(apantisiYesNo == 1){fprintf(output2bit,"Hit\n");}
			            sum_of_hits_2bit++;
                        nextpred = 'T';
                        }
                        else
                        {
                      		 if (pred == 't' && s == 0)
						 	 {
                             if(apantisiYesNo == 1){fprintf(output2bit,"Miss\n");}
                             nextpred = 'F';
                             }
                             else
                             {
                                  if (pred == 'f' && s == 1)
                                  {
                                  if(apantisiYesNo == 1){fprintf(output2bit,"Miss\n");}
                                  nextpred = 'T';
                                  }
                                  else
                                  {
                                       if (pred == 'f' && s == 0)
									   {
                                       if(apantisiYesNo == 1){fprintf(output2bit,"Hit\n");}
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



char predictor1bit(char pred,int s, int met)
{
	if (met == 1)
	{
	char nextpred;
    sum_of_klisis_1bit++;
    if(pred == 'T' && s == 1 ){
            if(apantisiYesNo == 1){fprintf(output1bit,"Hit\n");}
			sum_of_hits_1bit++;
            nextpred = 'T';
    }
    else if (pred == 'T' && s == 0){
         if(apantisiYesNo == 1){fprintf(output1bit,"Miss\n");}
         nextpred = 'F';
         
         }
         else if (pred == 'F' && s == 0){
              if(apantisiYesNo == 1){fprintf(output1bit,"Hit\n");}
			  sum_of_hits_1bit++;
              nextpred = 'F';
              }
              else if (pred == 'F' && s == 1){
                   if(apantisiYesNo == 1){fprintf(output1bit,"Miss\n");}
                   nextpred = 'T';
                   }
	return (nextpred);
	}
	else
	{
		char nextpred;
		sum_of_klisis_tournament++;
		if(pred == 'T' && s == 1 ){
				sum_of_hits_tournament++;
				changefield = 0;
				nextpred = 'T';
    }
    else if (pred == 'T' && s == 0){
		 changefield++;
		 nextpred = 'F';
         
         }
         else if (pred == 'F' && s == 0){
			  sum_of_hits_tournament++;
			  changefield = 0;
			  nextpred = 'F';
              }
              else if (pred == 'F' && s == 1){
                   changefield++;
				   nextpred = 'T';
                   }
	return (nextpred);
	}
}

char predictor11bit(char pred,int s,int met)
{
	if(met == 1)
	{
    char nextpred;
    sum_of_klisis_11bit++;
    
    if(pred == 'T' && s == 1 ){
           // if(apantisiYesNo == 1){fprintf(output11bit,"Hit\n");}
			sum_of_hits_11bit++;
            nextpred = 'T';
    }
    else if (pred == 'T' && s == 0){
         //if(apantisiYesNo == 1){fprintf(output11bit,"Miss\n");}
         nextpred = 'F';
         
         }
         else if (pred == 'F' && s == 0){
             // if(apantisiYesNo == 1){fprintf(output11bit,"Hit\n");}
			  sum_of_hits_11bit++;
              nextpred = 'F';
              }
              else if (pred == 'F' && s == 1){
                  // if(apantisiYesNo == 1){fprintf(output11bit,"Miss\n");}
                   nextpred = 'T';
                   }
     return(nextpred);
	}
	else
	{
		char nextpred;
		sum_of_klisis_tournament++;
		if(pred == 'T' && s == 1 ){
				sum_of_hits_tournament++;
				changefield = 0;
				nextpred = 'T';
    }
    else if (pred == 'T' && s == 0){
		 changefield++;
		 nextpred = 'F';
         
         }
         else if (pred == 'F' && s == 0){
			  sum_of_hits_tournament++;
			  changefield = 0;
			  nextpred = 'F';
              }
              else if (pred == 'F' && s == 1){
                   changefield++;
				   nextpred = 'T';
                   }
	return (nextpred);
	}
}
