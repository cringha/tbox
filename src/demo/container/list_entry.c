/* //////////////////////////////////////////////////////////////////////////////////////
 * includes
 */
#include "../demo.h"

/* //////////////////////////////////////////////////////////////////////////////////////
 * types
 */

// the demo entry type
typedef struct __tb_demo_entry_t 
{
    // the list entry
    tb_list_entry_t     entry;

    // the data
    tb_size_t           data;

}tb_demo_entry_t;

/* //////////////////////////////////////////////////////////////////////////////////////
 * main
 */
tb_int_t tb_demo_container_list_entry_main(tb_int_t argc, tb_char_t** argv)
{
    // init the entries
    tb_demo_entry_t entries[12] = 
    {
        {{0}, 0}
    ,   {{0}, 1}
    ,   {{0}, 2}
    ,   {{0}, 3}
    ,   {{0}, 4}
    ,   {{0}, 5}
    ,   {{0}, 6}
    ,   {{0}, 7}
    ,   {{0}, 8}
    ,   {{0}, 9}
    ,   {{0}, 10}
    ,   {{0}, 11}
    };

    // init the list
    tb_list_entry_head_t list;
    tb_list_entry_init(&list);

    // insert entries
    tb_list_entry_insert_tail(&list, &entries[5].entry);
    tb_list_entry_insert_tail(&list, &entries[6].entry);
    tb_list_entry_insert_tail(&list, &entries[7].entry);
    tb_list_entry_insert_tail(&list, &entries[8].entry);
    tb_list_entry_insert_tail(&list, &entries[9].entry);
    tb_list_entry_insert_head(&list, &entries[4].entry);
    tb_list_entry_insert_head(&list, &entries[3].entry);
    tb_list_entry_insert_head(&list, &entries[2].entry);
    tb_list_entry_insert_head(&list, &entries[1].entry);
    tb_list_entry_insert_head(&list, &entries[0].entry);

    // walk it
    tb_trace_i("insert: %lu", tb_list_entry_size(&list));
    tb_list_entry0_for_all(tb_demo_entry_t, item0, &list)
    {
        tb_trace_i("%lu", item0->data);
    }

    // trace
    tb_trace_i("");

    // replace entries
    tb_list_entry_replace_head(&list, &entries[10].entry);
    tb_list_entry_replace_last(&list, &entries[11].entry);

    // walk it
    tb_trace_i("replace: %lu", tb_list_entry_size(&list));
    tb_list_entry0_for_all(tb_demo_entry_t, item1, &list)
    {
        tb_trace_i("%lu", item1->data);
    }

    // trace
    tb_trace_i("");

    // remove entries
    tb_list_entry_remove_head(&list);
    tb_list_entry_remove_last(&list);

    // walk it
    tb_trace_i("remove: %lu", tb_list_entry_size(&list));
    tb_list_entry_for_all(tb_demo_entry_t, entry, item2, &list)
    {
        tb_trace_i("%lu", item2->data);
    }

    // trace
    tb_trace_i("");

    // moveto entries
    tb_list_entry_ref_t head = tb_list_entry_head(&list);
    tb_list_entry_moveto_head(&list, tb_list_entry_last(&list));
    tb_list_entry_moveto_tail(&list, head);

    // walk it
    tb_trace_i("moveto: %lu", tb_list_entry_size(&list));
    tb_list_entry_for_all(tb_demo_entry_t, entry, item3, &list)
    {
        tb_trace_i("%lu", item3->data);
    }

    // trace
    tb_trace_i("");

    // clear entries
    tb_list_entry_clear(&list);

    // walk it
    tb_trace_i("clear: %lu", tb_list_entry_size(&list));
    tb_list_entry_for_all(tb_demo_entry_t, entry, item4, &list)
    {
        tb_trace_i("%lu", item4->data);
    }

    // exit the list
    tb_list_entry_exit(&list);

    // trace
    tb_trace_i("");
    return 0;
}
