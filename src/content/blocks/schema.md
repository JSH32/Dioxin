**`block` schema**  
  
| |Type|Description|Required|  
|---|---|---|---|  
|**id**|`string`|The ID of the block, used to reference this block.| &#10003; Yes|  
|**texture**|`string`|Texture the item will use| &#10003; Yes|  
|**destructible**|`boolean`|Can the item be broken.| &#10003; Yes|  
|**item**|`string`|Item the block will drop. Only required if destructible is true|No|