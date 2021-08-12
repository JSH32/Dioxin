**`item` schema**  
  
| |Type|Description|Required|  
|---|---|---|---|  
|**id**|`string`|The ID of the item, used to reference this item.| &#10003; Yes|  
|**name**|`string`|Item name, will show in inventories.| &#10003; Yes|  
|**description**|`string`|Item description, will show in inventories| &#10003; Yes|  
|**texture**|`string`|Texture the item will use| &#10003; Yes|  
|**placeable**|`boolean`|Should the item be placeable as a block| &#10003; Yes|  
|**block**|`string`|ID of the block that should be placed, only required if placeable is true| No|  