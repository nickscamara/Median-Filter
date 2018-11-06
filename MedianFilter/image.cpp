/** CS515 Assignment 3
File: image.cpp
Name: Nicolas S Camara
Section: 1
Date: 9/26/2018
Collaboration Declaration: none
*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>
#include <sstream>

using namespace std;

int main( int argc, char ** argv )
{

  //Command Line varialbles
  string filename = "";
  string negative = "";
  string rotate = "";

  /////////////////////////
  string header = ""; //header / special characters
  string _width = "";
  string _height = "";
  string _MAX_GREY = "";

  //Negative value use 255 - a;

  if(argc == 4 )
  {
    try{

    filename = argv[1];
    negative = argv[2];
    rotate = argv[3];
  }catch(...)
  {
    cerr << "Invalid name or output, try again" << endl;
    return 0;
  }


    ifstream reader(filename);
    if(!reader.is_open())
    {
      cout << "Cannot open " << filename << " for input" << endl;
      return 0;
    }
    getline(reader,header);
    std::cout << "Image Special Characters: " << header << '\n';
    if(header.compare("P2") == true)
    {
      cout << "Try again" << endl;
      return 0;
    }
    reader >> _width;
    reader >> _height;
    reader >> _MAX_GREY;
    cout << "Width: " << _width << " Height: " << _height << " Max Grey: " << _MAX_GREY << endl;

    int width = stoi(_width); //convert the width to int;
    int height = stoi(_height);//convert the height to int;
    int MAX_GREY = stoi(_MAX_GREY);//convert the max gray scale to int;





    string hey = "";
    int** a = new int*[height];

    //Allocate
    for(int i = 0; i < height; ++i)
    {
      a[i] = new int[width]; // need to delete[] after using.
    }




    //Print




    ofstream saveFile (negative);

    saveFile << header << endl;
    saveFile << _width << " " << _height << endl;
    saveFile << _MAX_GREY << endl;

    //Fill Array
    for(int i = 0; i < height; ++i)
    {
      for(int j = 0; j < width; ++j)
      {
        reader >> hey;
        int heyy = stoi(hey);
        a[i][j] = MAX_GREY - heyy; // negative
        saveFile << a[i][j] << " ";// 255 - heyy = negative

      }
    }

     //need to save the header and then the inverted pixels;

    saveFile.close();

    //reader.close();
    //Delete arr[] after using
    for(int i = 0; i < height; ++i)
    {
      delete [] a[i];
    }
    delete [] a;



///////
    ifstream reader2(filename);
    getline(reader2,header);
    std::cout << "Image Special Characters: " << header << '\n';
    reader2 >> _width;
    reader2 >> _height;
    reader2 >> _MAX_GREY;
    cout << "Width: " << _width << " Height: " << _height << " Max Grey: " << _MAX_GREY << endl;

    int width2 = stoi(_width); //convert the width to int;
    int height2 = stoi(_height);//convert the height to int;
    int MAX_GREY2 = stoi(_MAX_GREY);//convert the max gray scale to int;

    //Create a Dynamic 2D array
    string hey2 = "";
    int** a2 = new int*[1000];

    //Allocate
    for(int i = 0; i < 1000; ++i)
    {
      a2[i] = new int[1000]; // need to delete[] after using.
    }

    ofstream saveFile2 (rotate);
    saveFile2 << header << endl;
    saveFile2 << _height << " " << _width << endl;
    saveFile2 << _MAX_GREY << endl;

    //Fill Array

    for(int i = 0; i < height2; ++i)
    {
      for(int j = 0; j < width2; ++j)
      {
        reader2 >> hey2;
        int heyy = stoi(hey2);
        a2[i][j] = heyy; // negative
        //saveFile << a[i][j] << " ";// 255 - heyy = negative

      }
    }

    for(int i = 0; i < width2; ++i)
    {
      for(int j = 0; j < height2; ++j)
      {
        saveFile2 << a2[height2-j-1][i] << " ";
      }
    }


    //Print Array
  //  for (int i = 0; i < height2; ++i)
    //{
      //  for (int j = 0; j < width2; ++j)
        //{
          //  std::cout << a2[height2-j-1][i] << ' ';
        //}
        //std::cout << std::endl;
    //}
     //need to save the header and then the inverted pixels;

    saveFile2.close();
    //reader.close();

    //Delete arr[] after using

    for(int i = 0; i < 1000; ++i)
    {
      delete [] a2[i];
    }
    delete [] a2;

    return 0;

  }
  else
  {
    if(argc < 4 || argc > 4)
    {
      cout << "Usage: image <input image> <neg image> <rotate image>" << endl;
    }
    else{
      cout << "Usage: image <input image> <neg image> <rotate image>" << endl;
    }

  }
  return 0;





}
