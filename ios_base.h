#pragma once
#include <string.h>

class ios_base {

public:

	/*class failure : public exception {

	public:

		explicit failure(const string& msg);
		virtual ~failure() throw();
		virtual const char* what() const throw();
	};*/

	typedef int      fmtflags;

	enum fmt_flags {
		boolalpha = 0x0001,
		dec = 0x0002,
		fixed = 0x0004,
		hex = 0x0008,
		internal = 0x0010,
		left = 0x0020,
		oct = 0x0040,
		right = 0x0080,
		scientific = 0x0100,
		showbase = 0x0200,
		showpoint = 0x0400,
		showpos = 0x0800,
		skipws = 0x1000,
		unitbuf = 0x2000,
		uppercase = 0x4000,
		adjustfield = left | right | internal,
		basefield = dec | oct | hex,
		floatfield = scientific | fixed
	};

	typedef int      iostate;

	enum io_state {
		goodbit = 0x00,
		badbit = 0x01,
		eofbit = 0x02,
		failbit = 0x04
	};

	typedef int      openmode;

	enum open_mode {
		app = 0x01,
		binary = 0x02,
		in = 0x04,
		out = 0x08,
		trunc = 0x10,
		ate = 0x20
	};

	typedef int      seekdir;

	enum seek_dir {
		beg = 0x0,
		cur = 0x1,
		end = 0x2
	};


	class Init;

	fmtflags flags() const;
	fmtflags flags(fmtflags fmtfl);
	fmtflags setf(fmtflags fmtfl);
	fmtflags setf(fmtflags fmtfl, fmtflags mask);
	void unsetf(fmtflags mask);

	/*streamsize precision() const;
	streamsize precision(streamsize prec);
	streamsize width() const;
	streamsize width(streamsize wide);

	locale imbue(const locale& loc);
	locale getloc() const*/

	static int xalloc();
	long& iword(int index);
	void*& pword(int index);

	ios_base& copyfmt(const ios_base& rhs);

	enum event {
		erase_event = 0x0001,
		imbue_event = 0x0002,
		copyfmt_event = 0x004
	};

	typedef void (*event_callback) (event, ios_base&,
		int index);
	void register_callback(event_callback fn, int index);

	bool synch_with_stdio(bool sync = true);
	bool is_synch();

protected:

	ios_base();
	virtual ~ios_base();

private:

	union ios_user_union {
		long  lword;
		void* pword;
	};

	union ios_user_union* userwords_;
};

ios_base& boolalpha(ios_base&);
ios_base& noboolalpha(ios_base&);
ios_base& showbase(ios_base&);
ios_base& noshowbase(ios_base&);
ios_base& showpoint(ios_base&);
ios_base& noshowpoint(ios_base&);
ios_base& showpos(ios_base&);
ios_base& noshowpos(ios_base&);
ios_base& skipws(ios_base&);
ios_base& noskipws(ios_base&);
ios_base& uppercase(ios_base&);
ios_base& nouppercase(ios_base&);
ios_base& internal(ios_base&);
ios_base& left(ios_base&);
ios_base& right(ios_base&);
ios_base& dec(ios_base&);
ios_base& hex(ios_base&);
ios_base& oct(ios_base&);
ios_base& fixed(ios_base&);
ios_base& scientific(ios_base&);
ios_base& unitbuf(ios_base&);
ios_base& nounitbuf(ios_base&);