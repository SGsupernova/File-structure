#ifndef __PURCHASE_TEST__
#define __PURCHASE_TEST__

#include "../classes/class_purchase.h"
#include "../../include/packing/recfile.h"
#include <fstream>
#include <vector>
#include "../environment.h"

void purchaseTest(Environment &env, int flag = 10) {
	ifstream ifs ("../resources/listOfPurchase.txt");
	char filename[ ] = "../built/fileOfPurchase.dat";


	if (ifs.fail()) {
		cout << "\"listOfPurchase.txt\" File open Error!" <<endl;
		exit(1);
	}
	
	int n = 0;
	ifs >> n;
	ifs.ignore (numeric_limits<streamsize>::max(), '\n');

	DelimFieldBuffer buffer ('|', PUR_MAX_BUF);
	RecordFile <Purchase> purchaseFile (buffer);

	// Write test
	purchaseFile.Create (filename, ios::out | ios::trunc);
	for (int i = 0; i < n; i++) {
		Purchase p;
		ifs >> p;

		int recAddr;
		if ((recAddr = purchaseFile.Write(p)) == -1) { cout << "Write Error!" << endl; }
		else {
			if (i < flag) { 
				cout << "Write at " << recAddr << endl;
			}
			else {
				env.purchaseData[p.getId()] = recAddr;
			}
		}
	}
	purchaseFile.Close ();


	if (!(flag < 0)) {
		// Read Test
		purchaseFile.Open (filename, ios::in);
		for (int i = 0; i < n; i++) {
			Purchase p;
			purchaseFile.Read(p);
			cout << p << endl;
		}
		purchaseFile.Close();
	}
};

#ifdef test_purchaseTest
int main() {
	Environment env;
	purchaseTest(env);

	return 0;
}
#endif

#endif
