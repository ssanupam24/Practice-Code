typedef struct header{
    unsigned int size;
    struct header* next;
} header_t;

static header_t base;
static header_t* freep = &base;
static header_t* usedp;

// Scan the free list and look for a place to put the
// block.

static void add_free_to_list(header_t* bp) {
    header_t* p;
    for (p = freep; )
}