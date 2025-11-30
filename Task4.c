#include<stdio.h>
#include<string.h>
struct movies{
	char Title[100];
	char genre[100];
	char director[100];
	int year;
	float rating;
};
struct movieInfo{
	struct movies movie[100];
	int count;
};
void Add(struct movieInfo *m){
	char temp[300];
	
	printf("\nWhat is the Name of the Movie: ");

	fgets(temp,sizeof(temp),stdin);
	temp[strcspn(temp,"\n")]='\0';
	strcpy(m->movie[m->count].Title,temp);
	
	printf("\nWhat is the Genre: ");
	fgets(temp,sizeof(temp),stdin);
	temp[strcspn(temp,"\n")]='\0';
	strcpy(m->movie[m->count].genre,temp);
	
	printf("\nWhat is the Name of Director: ");
	fgets(temp,sizeof(temp),stdin);
	temp[strcspn(temp,"\n")]='\0';
	strcpy(m->movie[m->count].director,temp);
	
	printf("\nEnter the Year of release: ");
	scanf("%d",&m->movie[m->count].year);
	
	while (getchar() != '\n');

	
	printf("\nEnter the Rating: ");
	scanf("%f",&m->movie[m->count].rating);	
	
	while (getchar() != '\n');

		
	m->count++;
	
}
void search(struct movieInfo *m){
	  char src[300];
	  int found=0;
	  int i;
	  printf("\nWhich Genre you want to search for(Write in Small Caps): ");
	  fgets(src,sizeof(src),stdin);
	  src[strcspn(src,"\n")]='\0';
	  for(i=0;i<m->count;i++){
	  	if(strstr(m->movie[i].genre,src)){
		  
		printf("\nMovie%d: %s",i+1,m->movie[i].Title);
	  		found++;
		  }
	}
	  if(found==0){
	  	printf("Not Found!!");
	  }
}
void display(struct movieInfo *m){
	int i;
	for(i=0;i<m->count;i++){
		printf("\nMovie%d:%s ",i+1,m->movie[i].Title);
		printf("\nGenre: %s",m->movie[i].genre);
		printf("\nDirector: %s",m->movie[i].director);
		printf("\nRating: %.1f",m->movie[i].rating);
		printf("\nReleased Year: %d",m->movie[i].year);
		printf("\n==================================\n");
	}	
}
int main(){
	struct movieInfo m;
	m.count=0;
	
	printf("\n=====Netfix=====\n");
	printf("\nWhat do you Want to do:\n(1)-Add New Movies,\n(2)-Search By Genre,\n(3)-Display all movies,\n(4)-Exit.");
	
	int choice;
	do{
		printf("\nEnter Your Choice: ");
			scanf("%d",&choice);
				getchar();
		switch(choice){
			case 1:
				Add(&m);
			break;
			
			case 2:
				search(&m);			
			break;
			
			case 3:
				display(&m);
			break;
			
			case 4:
				printf("\nExisting......");
			break;
			
			default:
					printf("\nInvalid Input");	
			break;		
		}
	}while(choice!=4);





}
