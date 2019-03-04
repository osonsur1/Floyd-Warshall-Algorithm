#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int dimensions;

void display(int dist_matrix[dimensions][dimensions]);

//function that implements floyd's algorithm
void floydsalg(int input_graph[100][100])
{
	int dist_matrix[dimensions][dimensions], i, j, k;

	for(i = 0; i < dimensions; i++)
	{
		for(j = 0; j < dimensions; j++)
		{
			//storing distance in dist_matrix from input_graph(that was read from input file)
			dist_matrix[i][j] = input_graph[i][j]; 
		}
	}

	for(k = 0; k < dimensions; k++)
	{
		for(i = 0; i < dimensions; i++)
		{
			for(j = 0; j < dimensions; j++)
			{
				if(dist_matrix[i][k] + dist_matrix[k][j] < dist_matrix[i][j])
				{
					//updating the distance to shortest path which uses intermediate vertice
					dist_matrix[i][j] = dist_matrix[i][k] + dist_matrix[k][j];
				}	
 			}	
		}
	}
	display(dist_matrix);
}

// the display function displays the distance matrix
void display(int dist_matrix[dimensions][dimensions])
{
	printf("The distance matrix is:\n");
	
	for(int i = 0; i < dimensions; i++)
	{
		for(int j = 0; j <  dimensions; j++)
		{
			if(dist_matrix[i][j] == 500)
			{
				printf("%s", "500");
			}
			else
			{
				printf("%d	", dist_matrix[i][j]);	
			}
		}
		printf("\n");
	}

}


//main function
void main(int argc, char **argv)
{
	char temp[100];
	char *rows, *line;
	
	//char filename = argv[1];
	int input_graph[100][100];
	FILE *fcontents = fopen(argv[1], "r");	//opens file in read mode
	int i = 0,j = 0;

	for(line; (line = fgets(temp, sizeof(temp), fcontents)) != NULL;)    //reads line from file stream and checks if not NULL
	{
		rows = strtok(line, ","); //breaks line into tokens by using delimiter comma i.e ","
		for(rows; rows != NULL;)
		{
			input_graph[i][j++] = atoi(rows);  //stores tokenized line in matrix row
			rows = strtok(NULL, ",");
		}
		i++ ;
		j = 0;
		dimensions++;
	}
	
	floydsalg(input_graph);
}
