#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct face{
    int** colors;     // 2 DIMENSION ARRAY THAT WE ARE KEEPING COLORS FOR EACH FACE
    struct face* leftFace;   // LEFT FACE OF STRUCT FACE
    struct face* rightFace;  // RIGHT FACE OF STRUCT FACE
    struct face* upFace;   // UP FACE OF STRUCT FACE
    struct face* downFace;   // DOWN FACE OF STRUCT FACE
};



int main()
{

    int shrinkNumber= 0;    // IF POINTER READS A "SHRINK" IT INCREASES
    int temp;     // TEMPORARY VALUES FOR SWAP
    int temp2;
    int buffer;
    int sizeOfCube;    // SIZE OF CUBE
    FILE *fp1;  // FILEPOINTER
    int i = shrinkNumber;
    int j = shrinkNumber;
    int faceToRotate;
    int rotateValue;
    char rowOrColumn[15];
    char rightOrLeft[15];
    char status[10];
    fp1 = fopen("commands.txt","r");

    fscanf(fp1,"%d",&sizeOfCube);
    fclose(fp1);
    struct face* face0 = malloc(sizeof(struct face));
    struct face* face1 = malloc(sizeof(struct face));
    struct face* face2 = malloc(sizeof(struct face));   // ALLOCATION
    struct face* face3 = malloc(sizeof(struct face));
    struct face* face4 = malloc(sizeof(struct face));
    struct face* face5 = malloc(sizeof(struct face));

    face0->colors = malloc(sizeof(int**)*sizeOfCube);
    face1->colors = malloc(sizeof(int**)*sizeOfCube);
    face2->colors = malloc(sizeof(int**)*sizeOfCube);   // ALLOCATION FOR 2 DIMENSION
    face3->colors = malloc(sizeof(int**)*sizeOfCube);
    face4->colors = malloc(sizeof(int**)*sizeOfCube);
    face5->colors = malloc(sizeof(int**)*sizeOfCube);



    while(i<sizeOfCube){
        face0->colors[i] = malloc(sizeof(int*)*sizeOfCube);
        i++;
    }

    i = 0;


    while(i<sizeOfCube){
        face1->colors[i] = malloc(sizeof(int*)*sizeOfCube);       // ALLOCATION FOR 1 DIMENSION
        i++;
    }

    i = 0;

    while(i<sizeOfCube){
        face2->colors[i] = malloc(sizeof(int*)*sizeOfCube);
        i++;
    }

    i = 0;


    while(i<sizeOfCube){
        face3->colors[i] = malloc(sizeof(int*)*sizeOfCube);
        i++;
    }

    i = 0;


    while(i<sizeOfCube){
        face4->colors[i] = malloc(sizeof(int*)*sizeOfCube);
        i++;
    }

    i = 0;


    while(i<sizeOfCube){
        face5->colors[i] = malloc(sizeof(int*)*sizeOfCube);
        i++;
    }

    i = 0;

    while(i<sizeOfCube){
        while(j<sizeOfCube){
            face0->colors[i][j] = 0;
            j++;
        }
        j = 0;
        i++;
    }


    i = 0;

    while(i<sizeOfCube){
        while(j<sizeOfCube){
            face1->colors[i][j] = 1;
            j++;
        }
        j = 0;                                     // FILLING WITH COLOR VALUES
        i++;
    }

    i = 0;

    while(i<sizeOfCube){
        while(j<sizeOfCube){
            face2->colors[i][j] = 2;
            j++;
        }
        j = 0;
        i++;
    }

    i = 0;

    while(i<sizeOfCube){
        while(j<sizeOfCube){
            face3->colors[i][j] = 3;
            j++;
        }
        j = 0;
        i++;
    }


    i = 0;

    while(i<sizeOfCube){
        while(j<sizeOfCube){
            face4->colors[i][j] = 4;
            j++;
        }
        j = 0;
        i++;
    }

    i = 0;

    while(i<sizeOfCube){
        while(j<sizeOfCube){
            face5->colors[i][j] = 5;
            j++;
        }
        j = 0;
        i++;
    }

    i = 0;
    j = 0;

    face0->downFace = face5;
    face0->leftFace = face3;
    face0->rightFace = face1;
    face0->upFace = face4;

    face1->downFace = face5;
    face1->leftFace = face0;
    face1->rightFace = face2;
    face1->upFace = face4;

    face2->downFace = face5;
    face2->leftFace = face1;         // FILLING LINKED LIST
    face2->rightFace = face3;
    face2->upFace = face4;

    face3->downFace = face5;
    face3->leftFace = face2;
    face3->rightFace = face0;
    face3->upFace = face4;

    face4->downFace = face0;
    face4->leftFace = face3;
    face4->rightFace = face1;
    face4->upFace = face2;

    face5->downFace = face2;
    face5->leftFace = face3;
    face5->rightFace = face1;
    face5->upFace = face0;
    i = 0;
    j = 0;
    fp1 = fopen("commands.txt","r");
    fscanf(fp1,"%d",&buffer);
    while(!feof(fp1)){
        fscanf(fp1,"%s ",status);
        i = shrinkNumber;
        j = shrinkNumber;
        if(strcmp("shrink",status) == 0){   // IF WE SEE SHRINK IT INCREASES
            shrinkNumber++;
        }
        else if(strcmp("rotate",status) == 0){
            fscanf(fp1,"%d %s %d %s\n",&faceToRotate,rowOrColumn,&rotateValue,rightOrLeft);
            rotateValue = shrinkNumber + rotateValue;
            i = shrinkNumber;
            j = shrinkNumber;
            if(strcmp(rowOrColumn,"row") == 0){
                if(strcmp(rightOrLeft,"right") == 0){
                    if(faceToRotate == 0){
                        while(j<sizeOfCube){
                            temp = face0->colors[rotateValue][j];
                            face0->colors[rotateValue][j] = face0->leftFace->colors[rotateValue][j];
                            temp2 = face0->rightFace->colors[rotateValue][j];
                            face0->rightFace->colors[rotateValue][j] = temp;
                            temp = face0->rightFace->rightFace->colors[rotateValue][j];
                            face0->rightFace->rightFace->colors[rotateValue][j] = temp2;
                            face0->leftFace->colors[rotateValue][j] = temp;
                            j++;
                        }


                    }

                    else if(faceToRotate == 1){
                        while(j<sizeOfCube){
                            temp = face0->colors[rotateValue][j];
                            face0->colors[rotateValue][j] = face0->leftFace->colors[rotateValue][j];
                            temp2 = face0->rightFace->colors[rotateValue][j];
                            face0->rightFace->colors[rotateValue][j] = temp;
                            temp = face0->rightFace->rightFace->colors[rotateValue][j];
                            face0->rightFace->rightFace->colors[rotateValue][j] = temp2;
                            face0->leftFace->colors[rotateValue][j] = temp;
                            j++;
                        }


                    }

                    else if(faceToRotate == 2){
                        while(j<sizeOfCube){
                            temp = face0->colors[rotateValue][j];
                            face0->colors[rotateValue][j] = face0->leftFace->colors[rotateValue][j];
                            temp2 = face0->rightFace->colors[rotateValue][j];
                            face0->rightFace->colors[rotateValue][j] = temp;
                            temp = face0->rightFace->rightFace->colors[rotateValue][j];
                            face0->rightFace->rightFace->colors[rotateValue][j] = temp2;
                            face0->leftFace->colors[rotateValue][j] = temp;
                            j++;
                        }


                    }
                    else if(faceToRotate == 3){
                        while(j<sizeOfCube){
                            temp = face0->colors[rotateValue][j];
                            face0->colors[rotateValue][j] = face0->leftFace->colors[rotateValue][j];
                            temp2 = face0->rightFace->colors[rotateValue][j];
                            face0->rightFace->colors[rotateValue][j] = temp;
                            temp = face0->rightFace->rightFace->colors[rotateValue][j];
                            face0->rightFace->rightFace->colors[rotateValue][j] = temp2;
                            face0->leftFace->colors[rotateValue][j] = temp;
                            j++;
                        }


                    }
                    else if(faceToRotate == 4){
                        while(j<sizeOfCube){
                            temp = face4->colors[rotateValue][j];
                            face4->colors[rotateValue][j] = face4->leftFace->colors[sizeOfCube-j-1][rotateValue];
                            temp2 = face4->rightFace->colors[j][sizeOfCube-rotateValue-1];
                            face4->rightFace->colors[j][sizeOfCube-rotateValue-1] = temp;
                            temp = face4->leftFace->downFace->colors[sizeOfCube-rotateValue-1][sizeOfCube-j-1];
                            face4->leftFace->downFace->colors[sizeOfCube-rotateValue-1][sizeOfCube-j-1] = temp2;
                            face4->leftFace->colors[sizeOfCube-j-1][rotateValue]  = temp;
                            j++;
                        }


                    }


                    else if(faceToRotate == 5){
                        rotateValue = sizeOfCube-rotateValue-1;
                        while(j<sizeOfCube){
                            temp = face4->colors[rotateValue][j];
                            face4->colors[rotateValue][j] = face4->rightFace->colors[j][sizeOfCube-rotateValue-1];
                            temp2 = face4->leftFace->colors[sizeOfCube-j-1][rotateValue];
                            face4->leftFace->colors[sizeOfCube-j-1][rotateValue] = temp;
                            temp = face4->leftFace->downFace->colors[sizeOfCube-rotateValue-1][sizeOfCube-j-1];
                            face4->leftFace->downFace->colors[sizeOfCube-rotateValue-1][sizeOfCube-j-1] = temp2;
                            face4->rightFace->colors[j][sizeOfCube-rotateValue-1] = temp;
                            j++;
                        }


                    }

                }
                else if(strcmp(rightOrLeft,"left") == 0){
                    if(faceToRotate == 0){
                        while(j<sizeOfCube){
                            temp = face0->colors[rotateValue][j];
                            face0->colors[rotateValue][j] = face0->rightFace->colors[rotateValue][j];
                            temp2 = face0->leftFace->colors[rotateValue][j];
                            face0->leftFace->colors[rotateValue][j] = temp;
                            temp = face0->leftFace->leftFace->colors[rotateValue][j];
                            face0->leftFace->leftFace->colors[rotateValue][j] = temp2;
                            face0->rightFace->colors[rotateValue][j] = temp;
                            j++;
                        }


                    }

                    else if(faceToRotate == 1){
                        while(j<sizeOfCube){
                            temp = face0->colors[rotateValue][j];
                            face0->colors[rotateValue][j] = face0->rightFace->colors[rotateValue][j];
                            temp2 = face0->leftFace->colors[rotateValue][j];
                            face0->leftFace->colors[rotateValue][j] = temp;
                            temp = face0->leftFace->leftFace->colors[rotateValue][j];
                            face0->leftFace->leftFace->colors[rotateValue][j] = temp2;
                            face0->rightFace->colors[rotateValue][j] = temp;
                            j++;
                        }


                    }

                    else if(faceToRotate == 2){
                        while(j<sizeOfCube){
                            temp = face0->colors[rotateValue][j];
                            face0->colors[rotateValue][j] = face0->rightFace->colors[rotateValue][j];
                            temp2 = face0->leftFace->colors[rotateValue][j];
                            face0->leftFace->colors[rotateValue][j] = temp;
                            temp = face0->leftFace->leftFace->colors[rotateValue][j];
                            face0->leftFace->leftFace->colors[rotateValue][j] = temp2;
                            face0->rightFace->colors[rotateValue][j] = temp;
                            j++;
                        }


                    }
                    else if(faceToRotate == 3){
                        while(j<sizeOfCube){
                            temp = face0->colors[rotateValue][j];
                            face0->colors[rotateValue][j] = face0->rightFace->colors[rotateValue][j];
                            temp2 = face0->leftFace->colors[rotateValue][j];
                            face0->leftFace->colors[rotateValue][j] = temp;
                            temp = face0->leftFace->leftFace->colors[rotateValue][j];
                            face0->leftFace->leftFace->colors[rotateValue][j] = temp2;
                            face0->rightFace->colors[rotateValue][j] = temp;
                            j++;
                        }


                    }
                    else if(faceToRotate == 4){
                        while(j<sizeOfCube){
                            temp = face4->colors[rotateValue][j];
                            face4->colors[rotateValue][j] = face4->rightFace->colors[j][sizeOfCube-rotateValue-1];
                            temp2 = face4->leftFace->colors[sizeOfCube-j-1][rotateValue];
                            face4->leftFace->colors[sizeOfCube-j-1][rotateValue] = temp;
                            temp = face4->leftFace->downFace->colors[sizeOfCube-rotateValue-1][sizeOfCube-j-1];
                            face4->leftFace->downFace->colors[sizeOfCube-rotateValue-1][sizeOfCube-j-1] = temp2;
                            face4->rightFace->colors[j][sizeOfCube-rotateValue-1] = temp;
                            j++;
                        }


                    }
                    else if(faceToRotate == 5){
                        rotateValue = sizeOfCube - rotateValue -1;
                        while(j<sizeOfCube){
                            temp = face4->colors[rotateValue][j];
                            face4->colors[rotateValue][j] = face4->leftFace->colors[sizeOfCube-j-1][rotateValue];
                            temp2 = face4->rightFace->colors[j][sizeOfCube-rotateValue-1];
                            face4->rightFace->colors[j][sizeOfCube-rotateValue-1] = temp;
                            temp = face4->leftFace->downFace->colors[sizeOfCube-rotateValue-1][sizeOfCube-j-1];
                            face4->leftFace->downFace->colors[sizeOfCube-rotateValue-1][sizeOfCube-j-1] = temp2;
                            face4->leftFace->colors[sizeOfCube-j-1][rotateValue]  = temp;
                            j++;
                        }


                    }

                }


            }






            else if(strcmp(rowOrColumn,"column") == 0){
                if(strcmp(rightOrLeft,"up") == 0){
                    if(faceToRotate == 0){
                        while(j<sizeOfCube){
                            temp = face0->colors[j][rotateValue];
                            face0->colors[j][rotateValue] = face5->colors[j][rotateValue];
                            temp2 = face4->colors[j][rotateValue];
                            face4->colors[j][rotateValue] = temp;
                            temp = face2->colors[sizeOfCube-j-1][sizeOfCube-rotateValue-1];
                            face2->colors[sizeOfCube-j-1][sizeOfCube-rotateValue-1] = temp2;
                            face5->colors[j][rotateValue] = temp;
                            j++;
                        }


                    }

                    else if(faceToRotate == 1){
                        rotateValue = sizeOfCube-rotateValue-1;
                        while(j<sizeOfCube){
                            temp = face4->colors[rotateValue][j];
                            face4->colors[rotateValue][j] = face4->rightFace->colors[j][sizeOfCube-rotateValue-1];
                            temp2 = face4->leftFace->colors[sizeOfCube-j-1][rotateValue];
                            face4->leftFace->colors[sizeOfCube-j-1][rotateValue] = temp;
                            temp = face4->leftFace->downFace->colors[sizeOfCube-rotateValue-1][sizeOfCube-j-1];
                            face4->leftFace->downFace->colors[sizeOfCube-rotateValue-1][sizeOfCube-j-1] = temp2;
                            face4->rightFace->colors[j][sizeOfCube-rotateValue-1] = temp;
                            j++;
                        }


                    }

                    else if(faceToRotate == 2){
                        rotateValue = sizeOfCube - rotateValue -1;
                        while(j<sizeOfCube){
                            temp = face0->colors[j][rotateValue];
                            face0->colors[j][rotateValue] = face4->colors[j][rotateValue];
                            temp2 = face5->colors[j][rotateValue];
                            face5->colors[j][rotateValue] = temp;
                            temp = face2->colors[sizeOfCube-j-1][sizeOfCube-rotateValue-1];
                            face2->colors[sizeOfCube-j-1][sizeOfCube-rotateValue-1] = temp2;
                            face4->colors[j][rotateValue] = temp;
                            j++;
                        }


                    }
                    else if(faceToRotate == 3){
                        while(j<sizeOfCube){
                            temp = face4->colors[rotateValue][j];
                            face4->colors[rotateValue][j] = face4->leftFace->colors[sizeOfCube-j-1][rotateValue];
                            temp2 = face4->rightFace->colors[j][sizeOfCube-rotateValue-1];
                            face4->rightFace->colors[j][sizeOfCube-rotateValue-1] = temp;
                            temp = face4->leftFace->downFace->colors[sizeOfCube-rotateValue-1][sizeOfCube-j-1];
                            face4->leftFace->downFace->colors[sizeOfCube-rotateValue-1][sizeOfCube-j-1] = temp2;
                            face4->leftFace->colors[sizeOfCube-j-1][rotateValue]  = temp;
                            j++;
                        }


                    }
                    else if(faceToRotate == 4){
                            while(j<sizeOfCube){
                            temp = face0->colors[j][rotateValue];
                            face0->colors[j][rotateValue] = face5->colors[j][rotateValue];
                            temp2 = face4->colors[j][rotateValue];
                            face4->colors[j][rotateValue] = temp;
                            temp = face2->colors[sizeOfCube-j-1][sizeOfCube-rotateValue-1];
                            face2->colors[sizeOfCube-j-1][sizeOfCube-rotateValue-1] = temp2;
                            face5->colors[j][rotateValue] = temp;
                            j++;
                        }


                    }
                    else if(faceToRotate == 5){
                            while(j<sizeOfCube){
                            temp = face0->colors[j][rotateValue];
                            face0->colors[j][rotateValue] = face5->colors[j][rotateValue];
                            temp2 = face4->colors[j][rotateValue];
                            face4->colors[j][rotateValue] = temp;
                            temp = face2->colors[sizeOfCube-j-1][sizeOfCube-rotateValue-1];
                            face2->colors[sizeOfCube-j-1][sizeOfCube-rotateValue-1] = temp2;
                            face5->colors[j][rotateValue] = temp;
                            j++;
                        }

                    }
                }

                else if(strcmp(rightOrLeft,"down") == 0){
                    if(faceToRotate == 0){
                        while(j<sizeOfCube){
                            temp = face0->colors[j][rotateValue];
                            face0->colors[j][rotateValue] = face4->colors[j][rotateValue];
                            temp2 = face5->colors[j][rotateValue];
                            face5->colors[j][rotateValue] = temp;
                            temp = face2->colors[sizeOfCube-j-1][sizeOfCube-rotateValue-1];
                            face2->colors[sizeOfCube-j-1][sizeOfCube-rotateValue-1] = temp2;
                            face4->colors[j][rotateValue] = temp;
                            j++;
                        }


                    }

                    else if(faceToRotate == 1){
                        rotateValue = sizeOfCube - rotateValue -1;
                        while(j<sizeOfCube){
                            temp = face4->colors[rotateValue][j];
                            face4->colors[rotateValue][j] = face4->leftFace->colors[sizeOfCube-j-1][rotateValue];
                            temp2 = face4->rightFace->colors[j][sizeOfCube-rotateValue-1];
                            face4->rightFace->colors[j][sizeOfCube-rotateValue-1] = temp;
                            temp = face4->leftFace->downFace->colors[sizeOfCube-rotateValue-1][sizeOfCube-j-1];
                            face4->leftFace->downFace->colors[sizeOfCube-rotateValue-1][sizeOfCube-j-1] = temp2;
                            face4->leftFace->colors[sizeOfCube-j-1][rotateValue]  = temp;
                            j++;
                        }


                    }

                    else if(faceToRotate == 2){
                        rotateValue = sizeOfCube - rotateValue -1;
                        while(j<sizeOfCube){
                            temp = face0->colors[j][rotateValue];
                            face0->colors[j][rotateValue] = face5->colors[j][rotateValue];
                            temp2 = face4->colors[j][rotateValue];
                            face4->colors[j][rotateValue] = temp;
                            temp = face2->colors[sizeOfCube-j-1][sizeOfCube-rotateValue-1];
                            face2->colors[sizeOfCube-j-1][sizeOfCube-rotateValue-1] = temp2;
                            face5->colors[j][rotateValue] = temp;
                            j++;
                        }


                    }
                    else if(faceToRotate == 3){
                        while(j<sizeOfCube){
                            temp = face4->colors[rotateValue][j];
                            face4->colors[rotateValue][j] = face4->rightFace->colors[j][sizeOfCube-rotateValue-1];
                            temp2 = face4->leftFace->colors[sizeOfCube-j-1][rotateValue];
                            face4->leftFace->colors[sizeOfCube-j-1][rotateValue] = temp;
                            temp = face4->leftFace->downFace->colors[sizeOfCube-rotateValue-1][sizeOfCube-j-1];
                            face4->leftFace->downFace->colors[sizeOfCube-rotateValue-1][sizeOfCube-j-1] = temp2;
                            face4->rightFace->colors[j][sizeOfCube-rotateValue-1] = temp;
                            j++;
                        }


                    }
                    else if(faceToRotate == 4){
                        while(j<sizeOfCube){
                            temp = face0->colors[j][rotateValue];
                            face0->colors[j][rotateValue] = face4->colors[j][rotateValue];
                            temp2 = face5->colors[j][rotateValue];
                            face5->colors[j][rotateValue] = temp;
                            temp = face2->colors[sizeOfCube-j-1][sizeOfCube-rotateValue-1];
                            face2->colors[sizeOfCube-j-1][sizeOfCube-rotateValue-1] = temp2;
                            face4->colors[j][rotateValue] = temp;
                            j++;
                        }


                    }
                    else if(faceToRotate == 5){
                        while(j<sizeOfCube){
                            temp = face0->colors[j][rotateValue];
                            face0->colors[j][rotateValue] = face4->colors[j][rotateValue];
                            temp2 = face5->colors[j][rotateValue];
                            face5->colors[j][rotateValue] = temp;
                            temp = face2->colors[sizeOfCube-j-1][sizeOfCube-rotateValue-1];
                            face2->colors[sizeOfCube-j-1][sizeOfCube-rotateValue-1] = temp2;
                            face4->colors[j][rotateValue] = temp;
                            j++;
                        }


                    }

                }


            }
        }

    }

fclose(fp1);
fp1 = fopen("result.txt","w");  // WRITING TO RESULT.TXT
i = shrinkNumber;
j = shrinkNumber;




while(i<sizeOfCube){
        while(j<sizeOfCube){
            fprintf(fp1,"%d ",face0->colors[i][j]);
            j++;

        }
        j = shrinkNumber;
        fprintf(fp1,"\n");
        i++;
    }
    i = shrinkNumber;
    j = shrinkNumber;

    fprintf(fp1,"\n");
    while(i<sizeOfCube){
        while(j<sizeOfCube){
            fprintf(fp1,"%d ",face1->colors[i][j]);
            j++;

        }
        j = shrinkNumber;
        fprintf(fp1,"\n");
        i++;
    }
    i = shrinkNumber;
    j = shrinkNumber;

    fprintf(fp1,"\n");
    while(i<sizeOfCube){
        while(j<sizeOfCube){
            fprintf(fp1,"%d ",face2->colors[i][j]);
            j++;

        }
        j = shrinkNumber;
        fprintf(fp1,"\n");
        i++;
    }
    i = shrinkNumber;
    j = shrinkNumber;

    fprintf(fp1,"\n");
    while(i<sizeOfCube){
        while(j<sizeOfCube){
            fprintf(fp1,"%d ",face3->colors[i][j]);
            j++;

        }
        j = shrinkNumber;
        fprintf(fp1,"\n");
        i++;
    }
    i = shrinkNumber;
    j = shrinkNumber;

    fprintf(fp1,"\n");
    while(i<sizeOfCube){
        while(j<sizeOfCube){
            fprintf(fp1,"%d ",face4->colors[i][j]);
            j++;

        }
        j = shrinkNumber;
        fprintf(fp1,"\n");
        i++;
    }
    i = shrinkNumber;
    j = shrinkNumber;

    fprintf(fp1,"\n");
    while(i<sizeOfCube){
        while(j<sizeOfCube){
            fprintf(fp1,"%d ",face5->colors[i][j]);
            j++;

        }
        j = shrinkNumber;
        fprintf(fp1,"\n");
        i++;
    }

fclose(fp1);
i = 0;







while(i<sizeOfCube){
        free(face0->colors[i]);
        free(face1->colors[i]);
        free(face2->colors[i]);
        free(face3->colors[i]);
        free(face4->colors[i]);
        free(face5->colors[i]);
        i++;
    }                                              //REALLOCATION

free(face0->colors);
free(face1->colors);
free(face2->colors);
free(face3->colors);
free(face4->colors);
free(face5->colors);













return 0;










}
