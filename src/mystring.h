#ifndef CPP_APPROVED_BY_HALLMANN
#define CPP_APPROVED_BY_HALLMANN

//// String Class by cmplx ////

#ifndef STRNAME
#define STRNAME Str
#endif

#define str(x) (cmplx::String() + x).c_str()
#define strn(x) (cmplx::String() + x)

#ifdef _WIN64

typedef unsigned long long unsigned_t;
typedef long long integer_t;

#else

typedef unsigned long unsigned_t;
typedef long integer_t;

#endif

namespace cmplx {

static char* strcpy(char* dest, const char* src) {
	for(; *src != '\0'; *dest++ = *src++)
		;
	return &(*dest = '\0');
}

static unsigned_t strlen(const char* str) {
	unsigned_t len;
	for(len = 0; *(str + len) != '\0'; len++)
		;
	return len;
}

static char* strcat(const char* src, const char* concat) {
	char* concatted = new char[strlen(src) + strlen(concat) + 1];
	strcpy(strcpy(concatted, src), concat);
	return concatted;
}

static char* itoa(integer_t value, integer_t minlen = 0) {
	static char buf[32] = {0};
	int i = 30;
	unsigned_t abs = value < 0 ? (unsigned_t)-value : (unsigned_t)value;
	for(; abs && i; abs /= 10) buf[i--] = "0123456789"[abs % 10];
	while(i > 30 - minlen) buf[i--] = '0';
	if(value < 0)
		buf[i] = '-';
	if(value == 0)
		buf[i] = '0';
	return &buf[i + (value > 0)];
}

static char* hextoa(void* value) {
	static char buf[19] = {0};
	int i = 17;
	unsigned_t abs = (unsigned_t)value;
	for(; abs && i; abs /= 16) buf[i--] = "0123456789ABCDEF"[abs % 16];
	if(value == 0)
		buf[i--] = '0';
	buf[i--] = 'x';
	buf[i] = '0';
	return &buf[i];
}

static void updateStr(char** pointer, char* newPointer) {
	delete[] * pointer;
	*pointer = newPointer;
}

static void strshift(char* toShift, char rangeTop, char rangeLower, char toAdd) {
	for(; *toShift != '\0'; toShift++) *toShift += toAdd * ((*toShift) <= rangeTop && (*toShift) >= rangeLower);
}

static bool strcmp(const char* first, const char* second) {
	bool eq = true;
	for(; eq && *first != '\0' || *second != '\0'; first++, second++) eq = *first == *second;
	return eq;
}

class String {

  private:
	char* strPtr;

	void init(const char* str) {
		if(strPtr)
			delete[] strPtr;
		strPtr = new char[strlen(str) + 1];
		strcpy(strPtr, str);
	}

	void defVal() {
		strPtr = 0;
		doNotDestroy = false;
	}

  public:
	~String() {
		if(!doNotDestroy)
			delete[] strPtr;
	};

	const char* c_str() { return strPtr; }
	unsigned_t len() { return strlen(strPtr); }
	void toLower() { strshift(strPtr, 'Z', 'A', 32); }
	void toUpper() { strshift(strPtr, 'z', 'a', -32); }
	void replace(char what, char replace) { strshift(strPtr, what, what, replace - what); };

	// dont free stringpointer on destructor if true
	bool doNotDestroy;

	// base constructors
	String() {
		defVal();
		init("");
	}
	String(const char* str) {
		defVal();
		init(str);
	}

	// constructor extensions
	String(const String& str) {
		defVal();
		init(str.strPtr);
	};
	String(integer_t num) {
		defVal();
		init(itoa(num));
	};
	String(int num) {
		defVal();
		init(itoa(num));
	}; // for old compilers
	String(double num) {
		defVal();
		integer_t x = (integer_t)((num - integer_t(num)) * 10000);
		if(x < 0)
			x = -x;
		init(itoa((integer_t)num));
		operator+=(".");
		operator+=(itoa(x, 4));
	}

	// set string
	void operator=(const char* str) { init(str); }
	void operator=(const String& str) { init(str.strPtr); }
	void operator=(integer_t num) { init(itoa(num)); }
	void operator=(int num) { init(itoa(num)); } // for old compilers
	void operator=(double num) { init(String(num).strPtr); }

	// compare string
	bool operator==(const char* str) { return strcmp(strPtr, str); }
	bool operator==(const String& str) { return strcmp(strPtr, str.strPtr); }

	// append to current string
	void operator+=(const char* concat) { updateStr(&strPtr, strcat(strPtr, concat)); }
	void operator+=(const String& concat) { operator+=(concat.strPtr); }
	void operator+=(integer_t num) { operator+=(itoa(num)); }
	void operator+=(int num) { operator+=(itoa(num)); } // for old compilers
	void operator+=(void* addr) { operator+=(hextoa(addr)); }
	void operator+=(double num) { operator+=(String(num)); }

	// concat return new string
	String operator+(const char* concat) {
		char* cat = strcat(strPtr, concat);
		String x(cat);
		delete[] cat;
		return x;
	}

	String operator+(const String& concat) { return operator+(concat.strPtr); }
	String operator+(integer_t num) { return operator+(itoa(num)); }
	String operator+(int num) { return operator+(itoa(num)); } // for old compilers
	String operator+(void* addr) { return operator+(hextoa(addr)); }
	String operator+(char ch) {
		char x[2] = {ch, 0};
		return operator+(x);
	}
	String operator+(double num) { return operator+(String(num)); }

	// index into string
	// returns nullpointer if overrange
	char& operator[](unsigned_t index) { return index >= len() ? *(char*)0 : strPtr[index]; }
};

} // namespace cmplx

// legacy typedef
typedef cmplx::String STRNAME;
#endif