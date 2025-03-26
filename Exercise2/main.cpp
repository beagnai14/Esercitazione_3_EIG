#include <iostream>
#include <iomanip>
#include "Eigen/Eigen"

using namespace std;
using namespace Eigen;

int main()
{
	cout << scientific << setprecision(1);
	
	// soluzione esatta
	Vector2d x_ex;
	x_ex << -1.0e+0, -1.0e+00;
	
		// esercizio 1
	
	Matrix2d A1;
	A1 << 5.547001962252291e-01, -3.770900990025203e-02,
          8.320502943378437e-01, -9.992887623566787e-01;
		  
	Vector2d b1;
	b1 << -5.169911863249772e-01, 1.672384680188350e-01;
	
	//PALU
	PartialPivLU<Matrix2d> palu1(A1);
	Vector2d x1_palu = palu1.solve(b1);
	
	//QR
	HouseholderQR<Matrix2d> qr1(A1);
	Vector2d x1_qr = qr1.solve(b1);
	
	//ERRORE RELATIVO 
	double err_rel_palu1 = (x1_palu - x_ex).norm() / ( x_ex.norm() );
	double err_rel_qr1 = (x1_qr - x_ex).norm() / ( x_ex.norm() );
	
	
	//soluzioni
	cout << "Soluzione fattorizzazione es 1 PALU: " << x1_palu << endl;
	cout << "Soluzione fattorizzazione es 1 QR: " << x1_qr << endl;
	cout << "Errore relativo es 1 PALU: " << err_rel_palu1 << endl;
	cout << "Errore relativo es 1 QR: " << err_rel_qr1 << endl;
		
		
	cout << endl;
	
		//esercizio 2
		
	Matrix2d A2;
	A2 << 5.547001962252291e-01,-5.540607316466765e-01,
		8.320502943378437e-01,-8.324762492991313e-01;
		  
	Vector2d b2;
	b2 << -6.394645785530173e-04, 4.259549612877223e-04;
	
	//PALU
	PartialPivLU<Matrix2d> palu2(A2);
	Vector2d x2_palu = palu2.solve(b2);
	
	//QR
	HouseholderQR<Matrix2d> qr2(A2);
	Vector2d x2_qr = qr2.solve(b2);
	
	//ERRORE RELATIVO 
	double err_rel_palu2 = (x2_palu - x_ex).norm() / ( x_ex.norm() );
	double err_rel_qr2 = (x2_qr - x_ex).norm() / ( x_ex.norm() );
	
	//soluzioni
	cout << "Soluzione fattorizzazione es 2 PALU: " << x2_palu << endl;
	cout << "Soluzione fattorizzazione es 2 QR: " << x2_qr << endl;
	cout << "Errore relativo es 2 PALU: " << err_rel_palu2 << endl;
	cout << "Errore relativo es 2 QR: " << err_rel_qr2 << endl;
	
	
	cout << endl;
	
		//esercizio 3 
	
	Matrix2d A3;
	A3 << 5.547001962252291e-01,-5.547001955851905e-01,
	8.320502943378437e-01,-8.320502947645361e-01;
		  
	Vector2d b3;
	b3 << -6.400391328043042e-10, 4.266924591433963e-10;
		
	//PALU
	PartialPivLU<Matrix2d> palu3(A3);
	Vector2d x3_palu = palu3.solve(b3);
	
	//QR
	HouseholderQR<Matrix2d> qr3(A3);
	Vector2d x3_qr = qr3.solve(b3);
	
	//ERRORE RELATIVO 
	double err_rel_palu3 = (x3_palu - x_ex).norm() / ( x_ex.norm() );
	double err_rel_qr3 = (x3_qr - x_ex).norm() / ( x_ex.norm() );
	
	//soluzioni
	cout << "Soluzione fattorizzazione es 3 PALU: " << x3_palu << endl;
	cout << "Soluzione fattorizzazione es 3 QR: " << x3_qr << endl;
	cout << "Errore relativo es 3 PALU: " << err_rel_palu3 << endl;
	cout << "Errore relativo es 3 QR: " << err_rel_qr3 << endl;
	
	
    return 0;
}
