#include <stdio.h>
#include <stdlib.h>

#define MAX_WEIGHT 250
#define MAX_ENTRY_COUNT 5

void view_weights(float *weights, int count);
float *get_user_weight(int *count);
float *update_weight(float *weights, int *count);

int main()
{

	printf("--| Terminal Weight Tracker |--\n");
	int choice;
	float *weights = NULL;
	int count = 0;

	do
	{
		printf("1. Create New Weight List\n");
		printf("2. Update Current Weight List\n");
		printf("3. View Current Weight List\n");
		printf("0. Exit\n");
		printf("> ");

		if (scanf("%d", &choice) != 1)
		{
			printf("Invalid input\n");
			while (getchar() != '\n');
			continue;
		}

		
		switch (choice)
		{
		case 1:
		{
			free(weights);

			weights = get_user_weight(&count);
			if (weights == NULL)
				printf("Please try again.\n");
			
			break;
		}
		case 2:
		{
			weights = update_weight(weights, &count);
			if (weights == NULL)
				printf("Please try again.\n");
			break;
		}
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
		printf("(MAXIMUM OF %d Count Per Entry)\n", MAX_ENTRY_COUNT);
		printf("How many weights to enter: ");
		scanf("%d", count);
	} while (*count <= 0 || *count > MAX_ENTRY_COUNT);

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
			} while (input <= 0 || input >= MAX_WEIGHT);
			weights[i] = input;
		}
	}
	return weights;
}

float *update_weight(float *weights, int *count)
{
	if (*count == 0)
	{
		printf("Current Weight Count is %d\n", *count);
		return NULL;
	}

	int new_count;
	do
	{
		printf("(MAXIMUM OF %d Count Per Entry)\n", MAX_ENTRY_COUNT);
		printf("How many additional weights to enter: ");
		scanf("%d", &new_count);
	} while (new_count <= 0 || new_count > MAX_ENTRY_COUNT);

	new_count += *count;

	float *new_weights = realloc(weights, sizeof(float) * new_count);

	if (new_weights == NULL)
	{
		printf("Failed realloc\n");
		return weights;
	}

	weights = new_weights;

	for (int i = *count; i < new_count; i++)
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

	*count = new_count;

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