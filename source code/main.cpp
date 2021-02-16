


#include <stdio.h>
#include <conio.h>
#include <windows.h>



void main_menu();
void fmenu();
void dmenu();
void displaylist();
void reports();

float total, total1, total2, total3, total4, total5, total6;
float balance;

int quantity[20];


int main()
{
	
	main_menu();
	
	return 0;
}


void main_menu()
{
	int choice;
	printf("#main menu#\n ");
	printf("\t1. Food menu\n");
	printf("\t2. Drink menu\n");
	printf("\t3. Check out\n");
	printf("Select your option: ");
	scanf("%d", &choice);
	system("cls");
	switch(choice)
	    {
	    	case 1:
	    		{
	    			fmenu();
	    			    break;
				}
	    	    
	    	case 2:
	    		{
	    			dmenu();
	    			    break;
				}
	    	    
	    	case 3:
	    	    {
	    	    	displaylist();
	    	            break;
				}
	    	default:
	    		{
	    			printf("\n Please Enter A Number\n");
	    			main_menu();
				}
	    }
}

void fmenu()
{
	
	char option = ' ';
	int t1, t2,t3;
	
	fflush(stdin);
	printf("#Food menu#\n");
	printf("\t1. Chicken chop  -RM10.00/unit\n");
	printf("\t2. Fish and chip -RM13.00/unit\n");
	printf("\t3. Beef stick    -RM11.50/unit\n");
	
	printf("Select your option: ");
	scanf("%c", &option);
	system("cls");
	switch(option)
	    {
	    	
	    	case '1':
	    	{
	    		printf("\nYou have selected chicken chop\n");
	    		printf("Enter quantity: ");
	    		scanf("%d", &t1);
	    		quantity[0]=t1+quantity[0];
	    		total1= 10.00*quantity[0];
	    		total= total+total1;
	    		    main_menu();
				    break;

			}
	    	    
	    	case '2':
	    	    {
	    	    	
	    	    	printf("\nYou have selected Fish and chip\n");
	    	    	printf("Enter quantity: ");
	    	    	scanf("%d", &t2);
	    	    	quantity[1]=t2+quantity[1];
					total2= 10.00*quantity[1];
					total= total+total2;
					    main_menu();
						break;
					    
				}
				
	    	case '3':
	    	    {
	    	    	printf("\nYou have selected Beef stick\n");
	    	    	printf("Enter quantity: ");
	    	    	scanf("%d", &t3);
	    	    	quantity[2]=t3+quantity[2];
	    	    	total3= 10.00*quantity[2];
	    	    	total= total+total3;
	    	    	main_menu();
	    	    	    break;
				}
			default:
			{
				fmenu();
				    break;
			}

		}
	
}

void dmenu()
{
	int t1, t2,t3;
	char option = ' ';
	fflush(stdin);
	printf("#Drink menu#\n");
	printf("\t1. Fresh orange  -RM3.00/unit\n");
	printf("\t2. Mango lassi   -RM3.50/unit\n");
	printf("\t3. Strawberry    -RM4.00/unit\n");
	printf("Select your option: ");
	scanf("%c", &option);
	system("cls");
	switch(option)
	{
		
		case '1':
		{
			printf("\nYou have selected Fresh orange\n");
	    	printf("Enter quantity: ");
	    	scanf("%d", &t1);
	    	quantity[3]=t1+quantity[3];
	    	total4= 3.00*quantity[3];
	    	total= total+total4;
	    	printf("\n");
	    	main_menu();
	    	    break;
	    	
		}
		case '2':
		{
			printf("\nYou have selected Mango lassi\n");
	    	printf("Enter quantity: ");
	    	scanf("%d", &t2);
	    	quantity[4]=t2+quantity[4];
	    	total5= 3.50*quantity[4];
	    	total= total+total5;
	    	main_menu();
					break;
	    	
		}
		case '3':
		{
			printf("\nYou have selected Strawberry\n");
	    	printf("Enter quantity: ");
	    	scanf("%d", &t2);
	    	quantity[5]=t2+quantity[5];
	    	total6= 4.00*quantity[5];
	    	total= total+total6;
	    	main_menu();
	    	break;
		}
		default:
		{
			printf("\n");
			dmenu();
			break;
		}
		
	}

}

void displaylist()
{
	
	float cash;
	char again;
	
	printf("\nORDER LIST\n");
	printf("Item                Price/ Unit        Quantity        Amount\n");
	printf("=========           ============       =========       =======\n");
	if (quantity[0]>0)
	{
		printf("Chicken Chop          10.00            %d                 %2.2f\n", quantity[0], total1);
	}
	if (quantity[1]>0)
	{
		printf("Fish and chip         13.00            %d                 %2.2f\n", quantity[1], total2);
	}
	if (quantity[2]>0)
	{
		printf("Beef stick            11.00            %d                 %2.2f\n", quantity[2], total3);
	}
	if (quantity[3]>0)
	{
		printf("Fresh orange          3.00             %d                 %2.2f\n", quantity[3], total4);
	}
	if (quantity[4]>0)
	{
		printf("Manggo Lassi          3.50             %d                 %2.2f\n", quantity[4], total5);
	}
	if (quantity[5]>0)
	{
		printf("Strawberry            4.00             %d                 %2.2f\n", quantity[5], total6);
	}
	printf("Total\t\t\t\t\t                 %2.2f\n", total);
	printf("\n");
	
	printf("Enter cash amount: ");
	scanf("%f",&cash);
	balance= cash-total;
	printf("\nYour balance: %2.2f\n", balance);
	printf("THANK YOU!!\n");
	printf("-----------------------------------------------------------\n");
	printf("Back to the main menu, click 'y'/ to exit, click 'n': \n");
	again= getch();
	{
		if (again == 'y')
		{
			system("cls");
			main_menu();
		}
		else
		{
			if (again == 'n')
			{
				reports();
			}
		}
	}
	
	
}

void reports()
{
	
	FILE *report;
	report = fopen("report.txt", "w");
	
	fprintf(report,"REPORT\n\n");
	fprintf(report, "Item                Price/ Unit        Quantity        Amount\n");
	fprintf(report, "=========           ============       =========       =======\n");
	if (quantity[0]>0)
	{
		fprintf(report, "Chicken Chop          10.00            %d                 %2.2f\n", quantity[0], total1);
	}
	if (quantity[1]>0)
	{
		fprintf(report, "Fish and chip         13.00            %d                 %2.2f\n", quantity[1], total2);
	}
	if (quantity[2]>0)
	{
		fprintf(report, "Beef stick            11.00            %d                 %2.2f\n", quantity[2], total3);
	}
	if (quantity[3]>0)
	{
		fprintf(report, "Fresh orange          3.00             %d                 %2.2f\n", quantity[3], total4);
	}
	if (quantity[4]>0)
	{
		fprintf(report, "Manggo Lassi          3.50             %d                 %2.2f\n", quantity[4], total5);
	}
	if (quantity[5]>0)
	{
		fprintf(report, "Strawberry            4.00             %d                 %2.2f\n", quantity[5], total6);
	}

	fprintf(report, "Total\t\t\t\t\t                 %2.2f\n", total);


}

