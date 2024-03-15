
**Disclaimer: non-official repo. The code is extracted from DeepStream6.4 docker image for personal research usage.**


## DeepStream Notes

### gst-nvdspreprocess

#### Extract frame meta from NvDsPreprocessBatch

> How to access frame metainfos, e.g. stream index, from [NvDsPreprocessBatch](https://docs.nvidia.com/metropolis/deepstream/dev-guide/sdk-api/structNvDsPreProcessBatch.html) in the [custom preprocess lib](/gst-nvdspreprocess/nvdspreprocess_lib/nvdspreprocess_lib.cpp#L100)?

![Alt text](https://g.gravizo.com/source/custom_mark1?https%3A%2F%2Fraw.githubusercontent.com%2FEnding2015a%2Fdeepstream6.4-gst-plugins%2Fmaster%2FREADME.md)

<details> 
<summary></summary>
custom_mark1
  digraph G {
    size ="4,4"
    batch [shape=box,label="NvDsPreprocessBatch*"];
    batch_meta [shape=box,label="NvDsBatchMeta*"];
    frame_meta_list [shape=box,label="NvDsFrameMetaList*"];
    frame_meta [shape=box,label="NvDsFrameMeta*"];
    pad_index [shape=box,label="guint"];
    batch -> batch_meta [label="batch->batch_meta"];
    batch_meta -> frame_meta_list [label="batch_meta->frame_meta_list"];
    frame_meta_list -> frame_meta [label="frame_meta_list->data"];
    frame_meta -> pad_index [label="data->pad_index"]
  }
custom_mark1
</details>

There are two ways to access the `frame_meta` stored in `frame_meta_list`:
1. Use `frame_meta_list->data` and `frame_meta_list->next`, refer to [gst-nvtracker/nvtracker_proc.cpp#L996-L1022](/gst-nvtracker/nvtracker_proc.cpp#L996-L1022):
```
for (NvDsFrameMetaList *l = batchMeta.frame_meta_list; l != nullptr; l = l->next)
{
    NvDsFrameMeta *pFrameMeta = (NvDsFrameMeta*)(l->data);
    // Do something...
}
```
2. Use official function [`nvds_get_nth_frame_meta`](https://docs.nvidia.com/metropolis/deepstream/dev-guide/sdk-api/group__metadata__structures.html#ga408cd1025e19d9ae28edf56c55f9cc3f) defined in `nvdsmeta.h`.

**Reference**

* [NvDsPreprocessBatch](https://docs.nvidia.com/metropolis/deepstream/dev-guide/sdk-api/structNvDsPreProcessBatch.html)
* [NvDsBatchMeta](https://docs.nvidia.com/metropolis/deepstream/dev-guide/sdk-api/struct__NvDsBatchMeta.html)
* [NvDsFrameMeta](https://docs.nvidia.com/metropolis/deepstream/dev-guide/sdk-api/struct__NvDsFrameMeta.html)
