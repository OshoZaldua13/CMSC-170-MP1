#include <iostream>
#include <list>

using namespace std;

class Node{
public:
    Node();
    Node(int[]);
    list<Node*> children;
    Node *parent;
    int puzzle[9];
    int x;
    void setPuzzle(int[]);
    bool goalTest();
    void moveLeft(int[], int); 
    void moveRight(int[], int); 
    void moveUp(int[], int); 
    void moveDown(int[], int); 
    void copyPuzzle(int[], int[]);
    void printPuzzle();
    bool samePuzzle(int[]);
    void moveAllDirections();

};

int main(){
    int array[9] = {
        1, 2, 4,
        3, 0, 5,
        7, 6, 8
    };

    Node n(array);
    n.moveAllDirections();
    //n.printPuzzle();
    list<Node*>::iterator it;
    for(it = n.children.begin();it!=n.children.end();++it){
        (*it)->printPuzzle();
        (*it)->parent->printPuzzle();
    }
    
}

Node::Node(){
    parent = NULL;
    x = 0;
    for(int i=0;i<9;i++)
        puzzle[i] = 0;
}

Node::Node(int arr[9]){
    setPuzzle(arr);
    parent = NULL;
    x = 0;
}

 void Node::setPuzzle(int arr[9]){
     for(int i=0;i<9;i++)
        puzzle[i] = arr[i];
 }

 bool Node::goalTest(){ //check if na solve na ba ang puzzle
    for(int i=0;i<9;i++)
        if(puzzle[i]!=i)
            return false;
    return true;
}

void Node::copyPuzzle(int p1[9], int p2[9]) {
    for(int i=0;i<9;i++) //gicopy ra jud ang array
        p1[i] = p2[i];
}

void Node::moveLeft(int arrPuzzle[9], int i){
    if(i%3 > 0) {
        int newArrPuzzle[9];
        copyPuzzle(newArrPuzzle, arrPuzzle); //copy para dili mawala
        newArrPuzzle[i] = newArrPuzzle[i-1];
        newArrPuzzle[i-1] = 0;

        Node* child = new Node(newArrPuzzle);
        children.push_back(child); //gi add sa list of children
        child->parent = this; //gi set nga mao ni ang parent ani nga child
    }
}

void Node::moveRight(int arrPuzzle[9], int i){ //same ra ang nahitabo sa moveLeft pero sa right lang ni
    if(i%3 < 2) {
        int newArrPuzzle[9];
        copyPuzzle(newArrPuzzle, arrPuzzle);
        newArrPuzzle[i] = newArrPuzzle[i+1];
        newArrPuzzle[i+1] = 0;

        Node* child = new Node(newArrPuzzle);
        children.push_back(child);
        child->parent = this;
    }
}

void Node::moveUp(int arrPuzzle[9], int i){ //same ra pud pero up ni duhhh
    if(i-3 >= 0) {
       int newArrPuzzle[9];
        copyPuzzle(newArrPuzzle, arrPuzzle);
        newArrPuzzle[i] = newArrPuzzle[i-3];
        newArrPuzzle[i-3] = 0;

        Node* child = new Node(newArrPuzzle);
        children.push_back(child);
        child->parent = this;
    }
}

void Node::moveDown(int arrPuzzle[9], int i){ //again same
    if(i +3 < 9) {
        int newArrPuzzle[9];
        copyPuzzle(newArrPuzzle, arrPuzzle);
        newArrPuzzle[i] = newArrPuzzle[i+3];
        newArrPuzzle[i+3] = 0;

        Node* child = new Node(newArrPuzzle);
        children.push_back(child);
        child->parent = this;
    }   
}

void Node::printPuzzle(){ //print puzzle
    int k = 0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            cout << puzzle[k++] << " ";
        cout << endl;
    }
    cout << endl;
}

bool Node::samePuzzle(int puzzleArr[9]){ //check if naa na bay nakapareha nga puzzle
    for(int i=0;i<9;i++)
        if(puzzle[i]!=puzzleArr[i])
            return false;
    return true;
}

void Node::moveAllDirections(){
    for(int i=0;i<9;i++)
        if(puzzle[i]==0)
            x = i; //gipangita kung unsa nga index ang blank tile
    
    moveLeft(puzzle, x);
    moveRight(puzzle, x);
    moveUp(puzzle, x);
    moveDown(puzzle, x);

}
