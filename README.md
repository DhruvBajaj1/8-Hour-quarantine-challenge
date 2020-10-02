# 8-Hour-quarantine-challenge
### Solution of Kill The Covid problem
#### Problem statement
https://docs.google.com/document/d/1nau-A04ZEBmeC3wfzCj1WBK4edYol2De6BadBlyyPE0/edit?usp=sharing
1. Hexagon Class : It contains name of Hexagon and an array of pointers where each pointer points to one of its neighboring 6 Hexagons if present, otherwise points to NULL.
2. addHexagon Method: It creates a new Hexagon with the specified name, set its neighbors and then update all the neigbors i.e, all the neighbors now have this new Hexagon as their neighbor.
3. getNeighbors Method: It prints all the neighbors of the Hexagon whose name is given.This is implemented by using the array of pointers to Hexagon that each Hexagon node contains.
4. removeHexagon Method: It makes sure that all its neighbors no longer have it as a neighbor and then delete the Hexagon.

![Diagram 1 4](https://user-images.githubusercontent.com/72250554/94904739-667f1f00-04b9-11eb-92c6-e9cbb20660dd.JPG)

## Sample run of the program

# Making diagram 1.4 by using addHexagon method again and again

![Making diagram 1 4](https://user-images.githubusercontent.com/72250554/94904865-99291780-04b9-11eb-8657-c595620b80e7.JPG)

![Making diagram 1 41](https://user-images.githubusercontent.com/72250554/94904993-c970b600-04b9-11eb-9451-0678a8afa2b7.JPG)

# Query for finding all the neighbors of Y

![Query for finding neighbors of Y](https://user-images.githubusercontent.com/72250554/94905063-e2796700-04b9-11eb-8102-98329f4cf21e.JPG)

# Adding a Hexagon N

![Adding Hexagon N](https://user-images.githubusercontent.com/72250554/94905094-f1f8b000-04b9-11eb-908a-eeb1c2f6bddc.JPG)

# Deleting Hexagon N

![Deleting Heaxagon N](https://user-images.githubusercontent.com/72250554/94905137-0046cc00-04ba-11eb-9289-cbf7702aeadb.JPG)
