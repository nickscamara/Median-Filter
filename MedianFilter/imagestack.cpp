/** CS515 Assignment 3
File: imagestack.cpp
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
#include <algorithm>
#include <iterator>
#include <utility>


using namespace std;




int main( int argc, char ** argv )
{

  //Command Line varialbles
  string filename = "";
  string output = "";
  /////////////////////////
  string header = ""; //header / special characters
  string _width = "";
  string _height = "";
  string _MAX_GREY = "";
  /////////////////////////
  string image = "";
  /////////////////////////


  int wid = 0;
  int hei = 0;
  int dep = 0;

  int images = argc - 2;



//  cout << "Argc: " << argc << endl;


  if(argc > 11 || argc <= 1)
  {
    cout << "Usage: ./imagestack <image1>.pgm <image2>.pgm ... <last_image>.pgm <output_file>.pgm" << endl;
    return 0;

  }
  else if( argc <= 11 && argc >= 4 )
  {
    filename = argv[1];
    ifstream reader(filename);
    getline(reader,header);
    std::cout << "Image Special Characters: " << header << '\n';
    reader >> _width;
    reader >> _height;
    int width = stoi(_width); //convert the width to int;
    int height = stoi(_height);//convert the height to int;

    int*** arr;
    arr = new int **[height]();


    for (int q = 0; q < height; q++)
    {
      arr[q] = new int *[width]();
      for (int j = 0; j < width; j++)
      {
          arr[q][j] = new int[argc-1]();
        }
    }

    for( int a = 1; a < argc-1; ++a  ) //argc - 1 because last one is output
    {
      cout << "Image: " << argv[a] << endl;
      filename = argv[a];
      ifstream reader(filename);
      getline(reader,header);
      std::cout << "Image Special Characters: " << header << '\n';
      reader >> _width;
      reader >> _height;
      reader >> _MAX_GREY;
      cout << "Width: " << _width << " Height: " << _height << " Max Grey: " << _MAX_GREY << endl;

      int width = stoi(_width); //convert the width to int;
      int height = stoi(_height);//convert the height to int;
      int MAX_GREY = stoi(_MAX_GREY);//convert the max gray scale to int;
      wid = width;
      hei = height;
      dep = argc - 2;
      //initialize 3D Array

      string hey = "";
      //cout<< "hello"<< endl;
      //passing the header to the output file
      //filling the array
      for(int i = 0; i < height; ++i)
      {
        for(int j = 0; j < width; ++j)
        {
          reader >> hey;
          int heyy = stoi(hey);
          arr[i][j][a]= heyy; // negative

        }
      }



//Delete arr[] after using, it is inside the for loop? / maybe check valgrind

/**

    for (int q = 0; q < height; ++q)
    {
      for (int j = 0; j < width; ++j)
      {
          delete[] arr[q][j];
      }
      delete[] arr[q];

    }
    delete[] arr;


    //return 0;
*/
    }

    output = argv[argc-1];
    ofstream saveFile (output);
    //cout << "output" << endl;
    saveFile << header << endl;
    saveFile << _width << " " << _height << endl;
    saveFile << _MAX_GREY << endl;

    for( int x  = 0; x < hei; x++ )
    {
      for( int y = 0; y < wid; y++ )
      {
        sort(arr[x][y], arr[x][y]+images);
        arr[x][y][0] = arr[x][y][images/2];
        saveFile <<  arr[x][y][0] << " ";
      }
    }
saveFile.close();
//reader.close();

for (int q = 0; q < height; ++q)
{
  for (int j = 0; j < width; ++j)
  {
      delete[] arr[q][j];

  }
  delete[] arr[q];

}
delete[] arr;

  }



  else{
    cout << "Usage: ./imagestack <image1>.pgm <image2>.pgm ... <last_image>.pgm <output_file>.pgm" << endl;
    return 0;
  }





  return 0;
}
