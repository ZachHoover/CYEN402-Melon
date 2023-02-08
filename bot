import discord, asyncio, socket
from discord.ext import tasks, commands

intents = discord.Intents.default()
intents.message_content = True

client = commands.Bot(intents = intents, command_prefix = '!')
global log_ctx

def write_log(ctx):
    global log_ctx
    log_ctx = str(ctx.channel.id)
    f = open("log.txt", "w")
    f.write(str(ctx.channel.id))
    f.close()

def read_log():
    f = open("log.txt", "r")
    ctx = f.read()
    f.close()
    return ctx


@client.event
async def on_ready():
    global log_ctx
    log_ctx = read_log()
    esp_comms.start()

@client.command()
async def log(ctx):
    print("Log")
    write_log(ctx)
    await ctx.send("Writing log to this channel. Channel ID: {}".format(ctx.channel.id))

@client.command()
async def ping(ctx):
    print("pong")
    await ctx.send('pong')

async def handle_client(reader, writer):
    print("Connected")
    request = None
    request = (await reader.read(255)).decode('utf8')
    if (str(request) != 'Melon'):
        writer.close()
        return
    while request != 'quit':
        request = (await reader.read(255)).decode('utf8')
        response = str(request)
        await client.get_channel(int(log_ctx)).send(response)
    writer.close()

@tasks.loop()
async def esp_comms():
    global log_ctx
    server = await asyncio.start_server(handle_client, '192.168.0.123', 7777)
    print("Started, serving to Channel: {}".format(log_ctx))
    await server.serve_forever()

   
        

client.run('MTA2MDY2ODIwNTAxNTc2MDk4Nw.GjIqAJ.WyYTpX2-FRr0gEuDdgRMiHNXQi3fjqqpcQAYRU')
