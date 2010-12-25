/*   
	Custom IOS Module (USB)

	Copyright (C) 2008 neimod.
	Copyright (C) 2009 WiiGator.
	Copyright (C) 2009 Waninkoko.

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _IOS_SYSCALLS_H_
#define _IOS_SYSCALLS_H_

#include "ipc.h"
#include "types.h"

/* IOS syscalls */
s32   os_thread_create(u32 (*entry)(void *arg), void *arg, void *stack, u32 stacksize, u32 priority, s32 autostart);
void  os_thread_set_priority(u32 priority);
s32   os_thread_get_priority(void);
s32   os_get_thread_id(void);
s32   os_get_parent_thread_id(void);
s32   os_thread_continue(s32 id);
s32   os_thread_stop(s32 id);
s32   os_message_queue_create(void *ptr, u32 id);
s32   os_message_queue_receive(s32 queue, u32 *message, u32 flags);
s32   os_message_queue_send(s32 queue, u32 message, s32 flags);
s32   os_message_queue_now(s32 queue, u32 message, s32 flags);
s32   os_heap_create(void *ptr, s32 size);
s32   os_heap_destroy(s32 heap);
void *os_heap_alloc(s32 heap, u32 size);
void *os_heap_alloc_aligned(s32 heap, s32 size, s32 align);
void  os_heap_free(s32 heap, void *ptr);
s32   os_device_register(const char *devicename, s32 queuehandle);
void  os_message_queue_ack(void *message, s32 result);
void  os_sync_before_read(void *ptr, s32 size);
void  os_sync_after_write(void *ptr, s32 size);
void  os_syscall_50(u32 unknown);
s32   os_open(const char *device, s32 mode);
s32   os_close(s32 fd);
s32   os_read(s32 fd, void *d, s32 len);
s32   os_write(s32 fd, void *s, s32 len);
s32   os_seek(s32 fd, s32 offset, s32 mode);
s32   os_ioctlv(s32 fd, s32 request, s32 bytes_in, s32 bytes_out, ioctlv *vector);
s32   os_ioctl(s32 fd, s32 request, void *in,  s32 bytes_in, void *out, s32 bytes_out);
s32   os_open_async(const char *device, s32 mode, void *ipc_cb, void *usrdata);
s32   os_close_async(s32 fd, void *ipc_cb, void *usrdata);
s32   os_ioctlv_async(s32 fd, s32 request, s32 bytes_in, s32 bytes_out, ioctlv *vector, ...);
s32   os_ioctl_async(s32 fd, s32 request, void *in,  s32 bytes_in, void *out, s32 bytes_out, ...);
s32   os_create_timer(s32 time_us, s32 repeat_time_us, s32 message_queue, s32 message);
s32   os_destroy_timer(s32 time_id);
s32   os_stop_timer(s32 timer_id);
s32   os_restart_timer(s32 timer_id, s32 dummy, s32 time_us);
s32   os_timer_now(s32 time_id); 
s32   os_register_event_handler(s32 device, s32 queue, s32 message);
s32   os_unregister_event_handler(s32 device);
s32   os_software_IRQ(s32 dev);
void  os_get_key(s32 keyid, void *out);
void *os_virt_to_phys(void *ptr);

/* ARM syscalls */
void write(const char *str);

#endif
