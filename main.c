#include <stdio.h>
#include <stdlib.h>


int main() 
{
	int troncal,capacidad,corrosion,capmixta,metal=0,hormigon=0, capmetal=0,caphormigon=0, mixta=0;
	char nombre[30],tipoconst,resp;
	float promedio;
	
	for(troncal=1; troncal<3; troncal++)
	{
		capmixta=0; 
		printf("\n\n\t troncal=%d",troncal);
		printf("\n hay puentes para registrar en la troncal?? S/N: ");
	    resp=tolower(getch());
		
		do{
		    printf("\n Nombre del Puente: ");
		    fflush(stdin);
		    gets(nombre);
		    printf("Tipo de construccion (M)metalico, (H)hormigon, (X)mixto: ");
		   fflush(stdin);
		    scanf(" %c",&tipoconst);
		    printf(" capacidad del puente: ");
		    scanf("%d",&capacidad);
		    printf("corrosion del puente en %%: ");
		    scanf("%d",&corrosion);
		    
		    if(tipoconst=='m' || tipoconst=='h')
		    {
		    	
		    	if(capacidad>=50 && corrosion>45)
		    	   printf("\n La via es de RIESGO\n");
		    	   
		    	  else
		            printf("\n la via es TRANSITABLE\n");	  
					
			   if(troncal==1)
			   {
			    	if(tipoconst=='m')
			    	{
			    		 metal+=1;
			    	}
			   	     
			   	      if(tipoconst=='h')
			   	      {
			   	      	hormigon+=1; 
	     	   	      }
				
			   }
					 
		    }	
		      
		   if(tipoconst=='x') 
		   {
		   	  printf("\n Su estado no es DEFINIDO\n");
		   	  capmixta+=1;
		   	  
		   	 
		    
		   }  
		  
		    if(tipoconst=='m' && corrosion>65)
	         capmetal+=1;
            	if(tipoconst=='h'  && corrosion>65 )
			      caphormigon+=1; 
                    	if(tipoconst=='x'  && corrosion>65 )
                    	    mixta+=1;
                     
			printf("\n hay mas puentes para registrar en la troncal?? S/N: ");
	        resp=tolower(getch());	
		
		
		}while(resp=='s');
		
		  	//ojo con el promedio
		  	if(capmixta==0)
		  	{
		  		printf("\n No hay puentes mixtos en la troncal");
		  	}
		  	 else
		  	 {
		  	 	 promedio=capmixta/troncal;
	        	 printf("\n\ntotal de puentes mixtos es %d el promedio es: %.2f",capmixta,promedio);
  	    
		  	 }
          	
	}
	   
	   printf("\n\n **RESPUESTAS**");
	  	 //menor de los puentes troncal 1
	  	 if(metal>hormigon)
			 printf("\n\n la menor cantidad de puentes en la troncal 1 es de hormigon"); 	    
	       	else
		   	 printf("\n\n la menor cantidad de puentes en la troncal 1 es de metal");
	
			// que troncal tiene menor puentes con mayor corrosion 	
    
 	 if(capmetal>caphormigon && capmetal>mixta && mixta>caphormigon)
			 printf("\n\n la menor cantidad de puentes esta en la troncal: %d es de hormigon",troncal);
		if(caphormigon>capmetal && caphormigon>mixta && mixta>capmetal)
			 printf("\n \n la menor cantidad de puentes esta en la troncal: %d es de metal",troncal);
			   else
			      printf("\n\n la menor cantidad de puentes esta en la troncal: %d es de mixta",troncal);	   	    
	   	
	return 0;
}

