/********************************************************************** 
Filename:  Ass0.c
Version:   1.0
Author:  Nana Ngassa Franck
Student No:   040 783 398
Course Name/Number: C++ CST 8219
Lab Sect:  011
Assignment #: 0
Assignment name: Animatiom Project In C
Due Date:  February 3 2018 
Submission Date: September 3 2018
Professor: Andrew Tyler
Purpose:   Until the user quits with option 4, adds frames to Animations from keyboard with option 1 
and delete all frames  with option 2. Then display the frames at 1 second interval with option 3
*********************************************************************/ 

//ass0.c
#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC	// need this to get the line identification
//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF); // in main, after local declarations
//NB must be in debug build

#include <crtdbg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BLOCK_SIZE 2

typedef enum { FALSE = 0, TRUE } BOOL;

typedef struct {
	char* fileName;			// Frame fileName
}Frame, *pFrame, **ppFrame;

typedef struct {
	unsigned int numFrames;		// number of Frame	
	ppFrame frames;			// array of Frame*
}Animation, *pAnimation;

// Forward declarations
void initAnimation(pAnimation);
void insertFrame(pAnimation);
void deleteFrames(pAnimation);
void runFrames(pAnimation);

/********************************************************************
Function name:
main Purpose:  main function
Calculates several properties of spheres.
In parameters:  none
Out parameters: 0 for successful execution
Version:  1.0
Author:   Andrew Tyler
**********************************************************************/

int main(void)
{
	char response;
	BOOL RUNNING = TRUE;
	Animation A;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	initAnimation(&A);

	while (RUNNING)
	{
		printf("MENU\n 1. Insert a Frame\n 2. Delete all the Frames\n 3. Run the Animation\n 4. Quit\n");
		scanf("%c", &response);
		switch (response)
		{
		case '1':insertFrame(&A); break;
		case '2':deleteFrames(&A); break;
		case '3':runFrames(&A); break;
		case '4':RUNNING = FALSE; deleteFrames(&A); break;
		default:printf("Please enter a valid option\n");
		}
		printf("\n");
		while ((response = getchar()) != '\n' && response != EOF);// clear input buffer
	}
	return 0;
}

/******************************************************************** 
Function Name:  runFrames 
Purpose:   run frames one by ine 
In parameters:  A pointer to Animation 
Out parameters:  Void 
Version:   1.0 
Author:   Andrew Tyler
**********************************************************************/

void runFrames(pAnimation pA)
{
    unsigned int counter = 0;
	time_t startsec, oldsec, newsec;

	if (pA->numFrames == 0)
	{
		printf("No frames in the animation\n");
		return;
	}

	printf("Run the Animation\n");
	startsec = oldsec = time(NULL);

	while (counter<(pA->numFrames))
	{
		newsec = time(NULL);
		if (newsec > oldsec)
		{
			printf("Frame #%d, time = %I64d sec\n", counter, newsec - startsec);
			printf("Image file name = %s\n", ((pA->frames)[counter++])->fileName);
			oldsec = newsec;
		}
	}
}

/********************************************************************
Function Name:  initAnimation
Purpose:   Initialize the Animation
In parameters:  A pointer to Animation
Out parameters:  void
Version:   1.0
Author:   Nana Ngassa Franck
**********************************************************************/

void initAnimation(pAnimation pA) {

	// Initialise our animation
	pA->frames = NULL;
	pA->numFrames = 0;
}
/********************************************************************
Function Name:  insertFrame
Purpose:   Insert frames in the animation
In parameters:  A pointer to Animation
Out parameters:  void
Version:   1.0
Author:   Nana Ngassa Franck
**********************************************************************/

void insertFrame(pAnimation pA) {

	if (pA->numFrames == 0) {
		pA->frames = malloc(sizeof(pFrame*)*BLOCK_SIZE); //Animation starts with the number of frames to 64 
	}

	//Increment animation capacity when full of frames.
	else if (pA->numFrames % BLOCK_SIZE == 0) {
		pA->frames = realloc(pA->frames, sizeof(pFrame*)*(BLOCK_SIZE + pA->numFrames)); 
	}

	//Hold Frame filename entered by user
	char filename[1024];
	printf("Insert a Frame In the Animation\n");
	printf("Enter the Frame filename: ");
	scanf("%s", filename);       
    unsigned int i = 0;

	//loops trough all frames in animation, print a error and exit if the frame to be added will result in a duplicate 
	while (i < pA->numFrames) {      
		int equal = strcmp(pA->frames[i]->fileName, filename);		
		if (equal == 0) {
			fprintf(stderr, "File already in!\n");
			return;
		}
		++i;
	}
		//Allocated memory for the frame the for the filename of the frame
	pA->frames[pA->numFrames] = malloc(sizeof(Frame));
	pA->frames[pA->numFrames]->fileName = malloc(strlen(filename)+1);

		//Add filename  frame to animation if not a duplicate and increment index
	strcpy(pA->frames[pA->numFrames]->fileName, filename);
	int blockcount = (pA->numFrames / BLOCK_SIZE) + 1; //Keeps track of the number of blocks
	printf("Number of blocks = %d", blockcount);
	pA->numFrames++;
}

/********************************************************************
Function Name:  deleteFrames
Purpose:   delete all frames from the animation
In parameters:  A pointer to Animation
Out parameters:  Void
Version:   1.0
Author:   Nana Ngassa Franck
**********************************************************************/

void deleteFrames(pAnimation pA) {

	unsigned int i = 0;

		//Is there something to free ?
	if (pA->numFrames != 0) {

		//Typical loop through animation to free memory that has been previously allocated for each frame.
		while (i < pA->numFrames) {

			free(pA->frames[i]->fileName);
			free(pA->frames[i]);
			++i;
		}
		//free the animation if there is one and reinitialize variables.
		if (pA->frames != NULL) {
			free(pA->frames);
			pA->frames = NULL;
		}
	}
	pA->numFrames = 0;
	printf("Franck Deleted All Frames from the Animation");
}	