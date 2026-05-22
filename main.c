#include <stdio.h>
#include <stdlib.h>

void view_weights(float *weights, int count);
float *get_user_weight(int *count);

int main()
{

	printf("--| Terminal Weight Tracker |--\n");
	int choice;
	float *weights = NULL;
	int count = 0;

	do
	{
		printf("1. Add New Weight\n");
		printf("2. Update Weight Count\n");
		printf("3. View All Weights\n");
		printf("0. Exit\n");

		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
		{
			weights = get_user_weight(&count);
			if (weights == NULL)
				printf("Please try again.\n");
			break;
		}
		case 2:
			break;
		case 3:
			view_weights(weights, count);
			break;
		case 0:
			break;
		default:
			printf("Invalid choice\n");
		}

	} while (choice != 0);

	free(weights);
	weights = NULL;

	printf("Thank you :)\n");

	return 0;
}

float *get_user_weight(int *count)
{
	do
	{
		printf("(MAXIMUM OF 10)\n");
		printf("How many weights to enter: ");
		scanf("%d", count);
	} while (*count <= 0 || *count > 10);

	float *weights = malloc(sizeof(float) * *count);

	if (weights == NULL)
		printf("Error malloc\n");
	else
	{
		for (int i = 0; i < *count; i++)
		{
			float input;
			do
			{
				printf("(Kilograms)\n");
				printf("Enter weight #%d: ", i + 1);
				scanf("%f", &input);
			} while (input <= 0 || input >= 250);
			weights[i] = input;
		}
	}
	return weights;
}

void view_weights(float *weights, int count)
{
	if (count == 0)
	{
		printf("No weights available\n");
	}
	else
	{
		printf("--| Weights Listed |--\n");

		float sum = 0;

		for (int i = 0; i < count; i++)
		{
			sum += weights[i];
			printf("Weight #%d: %.2f\n", i + 1, weights[i]);
		}

		printf("--| Average Weight: %.2f |--\n", sum / count);
	}
}