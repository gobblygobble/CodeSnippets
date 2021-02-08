# CodeSnippets
(Python & C++) code snippets meant to reduce work in the long run  

## Python snippets (`python/`)
1. `second_smallest_element.py`: get **second** smallest element from a list  
2. `parse_files/`: get all files in current working directory  

## C++ snippets (`cpp/`)
1. `argparse/`: parsing command-line arguments (*influenced by Y. Kwon, KAIST EE*)  
2. `subvector.cpp`: creating subvectors from existing vector  
3. `xd-vector/`: 2D and 3D `std::vector` **without** having to use `boost::multi_array` (`g++ -std=c++11`)  
4. `aggregate-duplicates.cpp`: aggregating duplicate key elements from vector to have no duplicate key elements using `std::map` (`g++ -std=c++11`)  
5. `concatenate-vectors.cpp`: aggregating multiple vectors into single vector (`g++ -std=c++11`)  

## Shell script snippets (`shell-script/`)
1. `git-updater.sh`: saves commit with current date/time + message given:  
e.g., `sh git-updater.sh "my message"` will result in something along the lines of  `git commit -m "1970.01.01 00:00:00 my message"`  

Copyright © Jinha Chung, KAIST School of Electrical Engineering
