#include "functions.h"

string convertMaskDecToBin(int subnetMaskInt) {
	string subnetMaskBinary = "";
	for (int i{ 0 }; i < 32; ++i) {
		if (i < subnetMaskInt)
			subnetMaskBinary += "1";
		else if (i < 32)
			subnetMaskBinary += "0";
		else
			cout << "Invalid mask!" << endl;
	}
	return subnetMaskBinary;
}
string calculateNetworkAddress(string ipaddress, string mask) {
	string networkaddress = "";
	for (int i{ 0 }; i < 32; ++i) {
		if ((ipaddress[i] == '1') && (mask[i] == '1'))
			networkaddress += "1";
		else
			networkaddress += "0";
	}
	return networkaddress;
}
void calculateNetworkClass(int firstOctet) {
	if (firstOctet < 128)
		cout << "Network class: A" << endl;
	else if (firstOctet < 193)
		cout << "Network class: B" << endl;
	else if (firstOctet < 225)
		cout << "Network class: C" << endl;
	else if (firstOctet < 241)
		cout << "Network class: D" << endl;
	else
		cout << "Network class: E" << endl;
}
string doBitwiseNOT(string subnetmask) {
	string subnetMaskBinaryNOT = "";
	for (int i{ 0 }; i < 32; ++i) {
		if (subnetmask[i] == '0')
			subnetMaskBinaryNOT += "1";
		else
			subnetMaskBinaryNOT += "0";
	}
	//cout << "\nSubnet mask NOT:\n" << subnetMaskBinaryNOT << endl;
	return subnetMaskBinaryNOT;
}
string calculateBroadcastAddress(string networkAddressBinary, string subnetMaskBinaryNOT) {
	string broadcastAddressBinary = "";
	for (int i{ 0 }; i < 32; ++i) {
		if (subnetMaskBinaryNOT[i] == '0')
			broadcastAddressBinary += networkAddressBinary[i];
		else
			broadcastAddressBinary += "1";
	}
	return broadcastAddressBinary;
}
void splitString(string binarystring, vector<string> &vect) {

	for (size_t i = 0; i < binarystring.size(); i += 8) {
		vect.push_back(binarystring.substr(i, 8));
	}
}
string convertDecToBin(const int octetsInt[], string octetsBinary[]){
	string IPAddressBinary = "";
	for (int i{ 0 }; i < 4; ++i) {
		octetsBinary[i] = bitset<8>(octetsInt[i]).to_string();
		IPAddressBinary += octetsBinary[i];
	}
	return IPAddressBinary;
}
void convertDecOctetToBinOctet(const int octetsInt[], string octetsBinary[]) {
	for (int i{ 0 }; i < 4; ++i) {
		octetsBinary[i] = bitset<8>(octetsInt[i]).to_string();
	}
}
void convertStringOctetToIntOctet(int finalIntOctet[], vector<string> splitStringOctet) {
	for (int i{ 0 }; i < 4; ++i) {
		finalIntOctet[i] = bitset<8>(splitStringOctet[i]).to_ulong();
		//cout << finalIntOctet[i] << "\n";
	}
}
void calculateFirstHostAddress(int octetsOfFirstHostAddressFinal[], int octetsOfNetworkAddressFinal[]) {
	for (int i{ 0 }; i < 4; ++i) {
		if (i < 3)
			octetsOfFirstHostAddressFinal[i] = octetsOfNetworkAddressFinal[i];
		if (i == 3)
			octetsOfFirstHostAddressFinal[i] = octetsOfNetworkAddressFinal[i] + 1;
	}
}
void calculateLastHostAddress(int octetsOfLastHostAddressFinal[], int octetsOfBroadcastAddressFinal[]) {
	for (int i{ 0 }; i < 4; ++i) {
		if (i < 3)
			octetsOfLastHostAddressFinal[i] = octetsOfBroadcastAddressFinal[i];
		if (i == 3)
			octetsOfLastHostAddressFinal[i] = octetsOfBroadcastAddressFinal[i] - 1;
	}
}
int calculateMaxHostNumber(int subnetmask) {
	int noOfZeros = 32 - subnetmask;
	int base = 2;
	int exp = noOfZeros;
	int ans = 1;

	for (int i = 0; i < noOfZeros; i++)
		ans *= base;
	return ans - 2;
}
void printToTheScreen(int octet[]) {
	for (int i{ 0 }; i < 4; ++i) {
		if (i < 3) {
			cout << octet[i] << ".";
		}
		if (i == 3)
			cout << octet[i];
	}
}
void printToTheScreen(vector<string> octet) {
	for (int i{ 0 }; i < 4; ++i) {
		if (i < 3) {
			cout << octet[i] << ".";
		}
		if (i == 3)
			cout << octet[i];
	}
}
void printToTheScreen(string octet[]) {
	for (int i{ 0 }; i < 4; ++i) {
		if (i < 3) {
			cout << octet[i] << ".";
		}
		if (i == 3)
			cout << octet[i];
	}
}

int checkIPAddress(string ipaddress, int subnetmask) {
	istringstream IPaddress(ipaddress);
	string octetsOfIPAddress [4];
	int octetsOfIPAddressInt[4];
	int subnetMaskInt = subnetmask;
	string subnetMask = to_string(subnetMaskInt);
	string octetsOfIPAddressBinary[4];
	string octetsOfMaskBinary[4];
	string firstHostAddressBinary[4];
	string lastHostAddressBinary[4];
	string IPAddressBinary = "";
	string subnetMaskBinary = "";
	string networkAddressBinary = "";
	string subnetMaskBinaryNOT = "";
	string broadcastAddressBinary = "";
	vector<string> IPAddressSplit;
	vector<string> MaskSplit;
	vector<string> NetworkAddressSplit;
	vector<string> BroadcastAddressSplit;
	int octetsOfIPAddressFinal[4];
	int octetsOfMaskFinal[4];
	int octetsOfNetworkAddressFinal[4];
	int octetsOfBroadcastAddressFinal[4];
	int octetsOfFirstHostAddressFinal[4];
	int octetsOfLastHostAddressFinal[4];
	int maxHostNumber;
	// - - - - C O D E - - - -
	// 2.1. check if address constists of digits and dots - related to 2.3. check if no of octets is 4
	const regex IPAddressPattern("([[:digit:]]+)((([[:digit:]]+)?)(([[:digit:]]+)?)?)\\.([[:digit:]]+)((([[:digit:]]+)?)(([[:digit:]]+)?)?)\\.([[:digit:]]+)((([[:digit:]]+)?)(([[:digit:]]+)?)?)\\.([[:digit:]]+)((([[:digit:]]+)?)(([[:digit:]]+)?)?)");

	if (regex_match(ipaddress, IPAddressPattern)) {
		// split the address
		for (int i{ 0 }; i < 4; ++i) {
			getline(IPaddress, octetsOfIPAddress[i], '.');
		}
		// convert string to int
		for (int i{ 0 }; i < 4; ++i) {
			stringstream convertToInt(octetsOfIPAddress[i]);
			convertToInt >> octetsOfIPAddressInt[i];
		}
		// 2.2. check if octets are in 0..255 range
		{
			bool flag = 1;
			for (int i{ 0 }; i < 4; ++i) {

				if (octetsOfIPAddressInt[i] < 0 || octetsOfIPAddressInt[i] > 255)
					flag = 0;
			}
			if (flag)
				cout << "All octets belong to 0..255 range" << endl;

			else {
				cout << "Invalid input!\nEach octet must belong to 0..255 range!" << endl;
				return 1;
			}
		}
		// 2.4. check if mask is in range 0..32
		{
			bool flag = 1;
				if (subnetMaskInt < 0 || subnetMaskInt > 32)
					flag = 0;
			if (flag)
				cout << "Mask belongs to 0..32 range" << endl;

			else {
				cout << "Invalid input!\nMask must belong to 0..32 range!" << endl;
				return 1;
			}
		}
	}
	else {
		cout << "Invalid input!\nThe IP address must consist of Xxx.Xxx.Xxx.Xxx where X is an obligatory and x is an extra number." << endl;
		return 1;
	}

	// 3.0
	// convert IP address from decimal to binary
	IPAddressBinary = convertDecToBin(octetsOfIPAddressInt, octetsOfIPAddressBinary);
	// convert mask from decimal to binary 
	// 3.3. full subnet mask
	subnetMaskBinary = convertMaskDecToBin(subnetMaskInt);
	// 3.1. calculate network address
	networkAddressBinary = calculateNetworkAddress(IPAddressBinary, subnetMaskBinary);
	// 3.2. calculate class of the network address
	//calculateNetworkClass(octetsOfIPAddressInt[0]); //below
	// 3.4. calculate broadcast address
	subnetMaskBinaryNOT = doBitwiseNOT(subnetMaskBinary);
	broadcastAddressBinary = calculateBroadcastAddress(networkAddressBinary, subnetMaskBinaryNOT);
	// split binary addresses
	splitString(IPAddressBinary, IPAddressSplit);
	splitString(subnetMaskBinary, MaskSplit);
	splitString(networkAddressBinary, NetworkAddressSplit);
	splitString(broadcastAddressBinary, BroadcastAddressSplit);
	// convert base 2 to base 10
	convertStringOctetToIntOctet(octetsOfIPAddressFinal, IPAddressSplit);
	convertStringOctetToIntOctet(octetsOfMaskFinal, MaskSplit);
	convertStringOctetToIntOctet(octetsOfNetworkAddressFinal, NetworkAddressSplit);
	convertStringOctetToIntOctet(octetsOfBroadcastAddressFinal, BroadcastAddressSplit);
	// 3.5. calculate first host address
	calculateFirstHostAddress(octetsOfFirstHostAddressFinal, octetsOfNetworkAddressFinal);
	convertDecOctetToBinOctet(octetsOfFirstHostAddressFinal, firstHostAddressBinary);
	// 3.6.calculate last host address
	calculateLastHostAddress(octetsOfLastHostAddressFinal, octetsOfBroadcastAddressFinal);
	convertDecOctetToBinOctet(octetsOfLastHostAddressFinal, lastHostAddressBinary);
	// 3.7 max host number in the network
	maxHostNumber = calculateMaxHostNumber(subnetMaskInt);
	
	// 4. showing the values on the screen
	cout << "\nIP Address \n(10):"; printToTheScreen(octetsOfIPAddressFinal);
	cout << "\n(2):"; printToTheScreen(IPAddressSplit); cout << endl;
	cout << "\nSubnet mask \n(10):"; printToTheScreen(octetsOfMaskFinal);
	cout << "\n(2):"; printToTheScreen(MaskSplit); cout << endl;
	cout << "\nNetwork address \n(10):"; printToTheScreen(octetsOfNetworkAddressFinal);
	cout << "\n(2):"; printToTheScreen(NetworkAddressSplit); cout << endl;
	cout << endl;
	calculateNetworkClass(octetsOfIPAddressInt[0]);
	cout << "\nBroadcast address \n(10):"; printToTheScreen(octetsOfBroadcastAddressFinal);
	cout << "\n(2):"; printToTheScreen(BroadcastAddressSplit); cout << endl;
	cout << "\nFirst host address \n(10):"; printToTheScreen(octetsOfFirstHostAddressFinal);
	cout << "\n(2):"; printToTheScreen(firstHostAddressBinary); cout << endl;
	cout << "\nLast host address \n(10):"; printToTheScreen(octetsOfLastHostAddressFinal);
	cout << "\n(2):"; printToTheScreen(lastHostAddressBinary); cout << endl;
	cout << "\nMax no of hosts: " << maxHostNumber << endl;
	cout << endl;
	return 0;
}
