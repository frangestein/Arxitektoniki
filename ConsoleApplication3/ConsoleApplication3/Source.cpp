#include <stdio.h>
#include <stdlib.h>

// dilosi predictors
char predictor1bit(char pred,int s);
char predictor2bit(char pred,int s);

int main(){
    // diktes se arxia
	FILE *input;
	FILE *output1bit;     
    FILE *output2bit;


    // arxikopiisi kai dilosi metavliton
	int k = 0;
	int ch = 0;
	int	n=0;
	int j = 1;
	int i = 0;
	int right1 =0;
	int right2 = 0;
	int counter = 0;
	int whileout = 0;
	int first = 0;
	int same = 0;
	int counter01 = 1;
	int sum_branches = 0;
	
	char prediction1_1bit='T';
	char prediction2_1bit='T';
	char prediction1_2bit='T';
	char prediction2_2bit='T';
	
	int pinakas[50][9];
	int pinakas_temp[3][9];
	
	//anigma arxion
	input=fopen("input.txt","r");
	if (!input)
    {
        printf("Can not find input file!!\n");       
        return 0;
    }
	output1bit=fopen("output1bit","w");
	output2bit=fopen("output2bit","w");
	
	// while atelioto mexri na vro EOF
	
	while (whileout == 0)
    {   
        // while mexri na vro 3is diaforetikes diefthinsis
		while(n!=3)
		{	
            //for gia to gemisma tou pinaka kai ton elexo ton stixion p lamvano apo to arxio
			for(i = 0; i < 8;i++) 
			{ 
                ch=fgetc(input);
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
                        n++;
                    }
                    else
                    {
                        pinakas[j][i] = ch;
                    }
				}
				// exo provlima edo chek it later!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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
                                      for(i=0;i<8;i++)
                                      {
                                                      pinakas_temp[1][i] = pinakas[j][i];
                                      }
                                      n++;
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
                             
                             if((right1 != 8) &&(right2 != 8))
                             {
                                       for(i = 0;i < 8;i++)
                                       {
                                              pinakas_temp[2][i] = pinakas[j][i];
                                       }
                                       n++;
                                       sum_branches = sum_branches + 2;
                                                       
                             }                              
                     }
                 }
                 
				// edo vriskome sto for
			}// telos for
// edo vriskome sto while (n!=3)
            
			first = 1;
			j++;
		}//telos while(n!=3
		
		// arxikopiisi timon
		right1 = 0;
		right2 = 0;
		
		/*//predictors place calling
		
		for(k = 0;k < j; k++)
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
                      prediction1_1bit = predictor1bit(char prediction1_1bit,int same);
                      prediction1_2bit = predictor2bit(char prediction1_2bit,int same);
              }
              else
              {
                      if( same == 1 && counter01 == 2)
                      {
                          prediction2_1bit = predictor1bit(char prediction2_1bit,int same);
                          prediction2_2bit = predictor2bit(char prediction2_2bit,int same);
                      }
                      else
                      {
                          if( same == 0 && counter01 == 1)
                          {
                              prediction1_1bit = predictor1bit(char prediction1_1bit,int same);
                              prediction1_2bit = predictor2bit(char prediction1_2bit,int same);
                              counter01++;
                          }
                          else
                          {
                              if( same == 0 && counter01 == 2)
                              {
                                  prediction2_1bit = predictor1bit(char prediction2_1bit,int same);
                                  prediction2_2bit = predictor2bit(char prediction2_2bit,int same);
                                  counter01--;
                              }
                          }
              }
              counter = 0;
              
              
        }//predictor calling ending */
        
        
        // anathesi tis tritis diefthinsis p den eleksa stin proti thesi tou kenourgiou m pinaka
        for(i = 0;i < 9; i++)
        {
              pinakas[0][i] = pinakas_temp[2][i];
        }
        //arxikopiisi timon gia ton kenourgio pinaka
        n=1;
        counter01 = 1;
        j = 1;
        
       	 prediction1_1bit='T';
         prediction2_1bit='T';
         prediction1_2bit='T';
         prediction2_2bit='T';
        
	    }
	

	fclose(input);
	fclose(output1bit);
	fclose(output2bit);

	
}
/*
char predictor2bit(char pred,int s){
     char nextpred;
     if (pred == 'T' && s == 1 ){
        fprintf(output2bit,"Hit");
        nextpred = 'T';
    }
    else if (pred == 'T' && s == 0){
         fprintf(output2bit,"Miss");
         nextpred = 't';
         }
         else if (pred == 'F' && s == 0){
              fprintf(output2bit,"Hit");
              nextpred = 'F';
              }
              else if (pred == 'F' && s == 1){
                   fprintf(output2bit,"Miss");
                   nextpred = 'f';
                   }
                   else if (pred == 't' && s == 1){
                        fprintf(output2bit,"Hit");
                        nextpred = 'T';
                        }
                        else if (pred == 't' && s == 0){
                             fprintf(output2bit,"Miss");
                             nextpred = 'F';
                             }
                             else if (pred == 'f' && s == 1){
                                  fprintf(output2bit,"Miss");
                                  nextpred = 'T';
                                  }
                                  else if (pred == 'f' && s == 0){
                                       fprintf(output2bit,"Miss");
                                       nextpred = 'F';
                                       }
	return (nextpred);
          
}*/



/*char predictor1bit(char pred,int s){
	char nextpred;
    
    if(pred == 'T' && s == T ){
            fprintf(output1bit,"Hit");
            nextpred = 'T';
    }
    else if (pred == 'T' && s == F){
         fprintf(output1bit,"Miss");
         nextpred = 'F';
         }
         else if (pred == 'F' && s == F){
              fprintf(output1bit,"Hit");
              nextpred = 'F';
              }
              else if (pred == 'F' && s == T){
                   fprintf(output1bit,"Miss");
                   nextpred = 'T';
                   }
	return (nextpred);
}*/
