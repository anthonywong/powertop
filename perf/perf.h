
using namespace std;

class  perf_event {
protected:
	int perf_fd;
	void * perf_mmap;
	void * data_mmap;
	struct perf_event_mmap_page *pc;



	int bufsize;
	char *name;
	unsigned int trace_type;
	void create_perf_event(char *eventname);

public:
	perf_event(const char *event_name, int buffer_size = 128);
	void set_event_name(const char *event_name);

	void start(void);
	void stop(void);
	void clear(void);

	void process(void);

	virtual void handle_event(struct perf_event_header *header) { };
};
