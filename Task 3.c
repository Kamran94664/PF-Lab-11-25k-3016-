#include<stdio.h>
#include<string.h>

struct flightInformation{
int	flightNumber;
char depCity[50];
char desCity[50];
int availableSeat;
char date[30];
};
void display(struct flightInformation *f,int l){

		printf("\n=======INFO=======");
		
		printf("\nThe Flight Number is: %d",f->flightNumber);
		
		printf("\nThe Departure City is: %s",f->depCity);
		
		printf("\nThe Destination City is: %s",f->desCity);
		
		printf("\nAt Date: %s",f->date);
		
		printf("\nThe Numeber of seats are:%d ",l);
}

void bookflight(struct flightInformation *f){
	int k;
	
	printf("\nEnter Flight Number: ");
    scanf("%d", &f->flightNumber);

    printf("Enter Departure City: ");
    scanf("%s", f->depCity);

    printf("Enter Destination City: ");
    scanf("%s", f->desCity);

    printf("How many seats do you want (Available: %d): ", f->availableSeat);
    scanf("%d", &k);
	
	if(k>f->availableSeat){
		printf("\nEnter A valid Number of Seats; ");	
		return;	
	}
	else{
   		f->availableSeat -= k;	
	}
    printf("\nEnter Date of Departure: ");
    scanf("%s", f->date);

    display(f, k);
	
}


int main(){
	struct flightInformation f;

	
    printf("How many seats are available initially: ");
    scanf("%d", &f.availableSeat);

    bookflight(&f);
}
