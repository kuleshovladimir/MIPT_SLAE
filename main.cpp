#include "iostream"
#include "vector"
#include "map"

using std::cout;
using std::endl;

class Matrix{
private:
    int n, m; // dimensions of the matrix
    std::vector<double>matrix; //matrix in vector
    //std::vector<int>free_column; <- ???
public:
    //constructor for coefficient matrix
    Matrix(int _n, int _m, const std::vector<double>& _matrix) : n(_n), m(_m + 2) {
        matrix.resize(n * m, 0);
        for (int k = 0; k < _n * _m; k++) {
            int i = k / _m, j = k - i * _m;
            //(i, j) -> (i, j + 1)
            matrix[i * m + j + 1] = _matrix[k];
            //this->printMatrix();
        }
    };
    //constructor for free column
    Matrix(int _n, const std::vector<double>& _matrix) : n(_n), m(1), matrix(_matrix){};

    //the general way of setting the matrix
    Matrix(int _m, int _n) : n(_n), m(_m + 2) {
        matrix.resize(m * n, 0);//empty matrix
    }
    //Matrix(const Matrix& _mtr) : m(_mtr.m), n(_mtr.n), matrix(_mtr.matrix){}; //copying of the matrix

    /*Matrix & operator=(const Matrix& mtr){ //assignment operator
        m = mtr.m;
        n = mtr.n;
        matrix = mtr.matrix;
        return *this;
    }*/

    void printMatrix() {
        cout << n << " " << m << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << this->at(i, j) << " ";
            }
            cout << endl;
        }
    }

    std::pair<int, int> DimOfMatrix(){
        std::pair<int, int> p(m, n);
        return p;
    }

    std::vector<double>& VectorOfMatrix(){
        return matrix;
    }

    double& at(int i, int j) {
        //cout << i << " " << j << endl;
        int ind = i * m + j;
        //cout << ind << endl;
        return matrix[ind];
    }

    //three diagonal method

    double& getA(int n) {
        return this->at(n, n); //matrix.at(n, n)
    }

    double& getB(int n) {
        return this->at(n, n + 1); //matrix.at(n, n)
    }

    double& getC(int n) {
        return this->at(n, n + 2); //matrix.at(n, n)
    }

    double& getD(int n) {
        return this->at(n, 0); //matrix.at(n, n)
    }

    //
    /*std::vector<int> static FreeColumn(const Matrix mtr){
        std::vector<int> p(mtr.free_column);
        return p;
    }*/
//    friend Matrix operator+(const Matrix& _mtr) { //addition operator
//        Matrix mtr(n, m);
//        mtr += _mtr;
//        return mtr;
//    }
//    Matrix& operator +=(const Matrix& _mtr) {
//        // чото осмысленное
//    }

    friend class Solver_tree_diagonal_method;
};

class Solver_tree_diagonal_method{
private:
    int m, n;
    Matrix coef, free;
    std::vector<float> sol;
public:
    Solver_tree_diagonal_method(int _m, int _n, const std::vector<double>& _matrix, const std::vector<double>& _free_column):
            m(_m), n(_n), coef(_m, _n, _matrix), free( _n, _free_column){};
    void solve(){
        std::vector<float> p, q;
        p.push_back(- coef.getC(0) / coef.getB(0));
        q.push_back(free.at(0, 0) / coef.at(0, 1));

        for (int i = 0; i < n - 1; i++) {
            p.push_back(-coef.getC(i) / (coef.getA(i) * p[i] + coef.getB(i)));
            // add check non zero denominator
            q.push_back((free.getD(i) - coef.getA(i) * q[i]) / (coef.getA(i) * p[i] + coef.getB(i)));
        }

        sol.resize(0);
        sol.push_back((free.getD(n - 1) - coef.getA(n - 1) * q[n - 1])/(coef.getA(n - 1) * p[n - 1] + coef.getB(n - 1)));

        for (int i = 0; i < n - 1; i ++) {
            sol.push_back(p[n - i -1] * sol[i] + q[n - i - 1]);
        }
        std::reverse(sol.begin(), sol.end());
    }
    void printSolution(){
        for (int i = 0; i < sol.size(); i++)
            std::cout << sol[i] << " ";
        cout << endl;
    }
};

int main(){
    int n = 3, m = 3;
    std::vector<double> v = {1, 2, 0, 3, 4, 5, 0, 6, 7};
    std::vector<double> l = {4, 3, 2};
    Solver_tree_diagonal_method sol(n, m, v, l);
    sol.solve();
    sol.printSolution();
    return 0;
}

